// move.c
// Modified by Eatdami@MX (10/05/2000)

//#define TIME_TICK (time()*60)
#define MAX_ITEM_SUM    30

//#include <localtime.h>

#include <dbase.h>
#include <room.h>

nosave int weight = 0;
nosave int encumb = 0, max_encumb = 0;

nomask int query_encumbrance() { return encumb; }
nomask int over_encumbranced() { return encumb > max_encumb; }

nomask int query_max_encumbrance() { return max_encumb; }
nomask void set_max_encumbrance(int e) { max_encumb = e; }
        
nomask void add_encumbrance(int w)
{
        encumb += w;
        if( encumb < 0 ) {
                encumb = 0;
                log_file("move.bug", sprintf("%O encumbrance underflow.\n", this_object()));
        }
        if( encumb > max_encumb ) this_object()->over_encumbrance();
        if( environment() ) environment()->add_encumbrance(w);
}

void over_encumbrance()
{
        if( !interactive(this_object()) ) return;
        tell_object(this_object(), "你的负荷过重了！\n");
}

nomask int query_weight() { return weight; }
nomask void set_weight(int w)
{
        if( w < 0 ) w = 0;
        if( !environment() ) {
                weight = w;
                return;
        }
        if( w!=weight ) environment()->add_encumbrance( w - weight );
        weight = w;
}


// This is the "current" weight of an object, which is used on weight
// checking in move().
nomask int weight() { return weight + encumb; }

varargs int move(mixed dest, int silently)
{
        object ob, env,*inv,thisob;
        string str;
        int i,sum;

        // If we are equipped, unequip first.
        if( query("equipped") && !this_object()->unequip() )
                return notify_fail("你没有办法取下这样东西。\n");

        // Find the destination ob for moving.
        if( objectp(dest) )
                ob = dest;
        else if( stringp(dest) ) {
                call_other(dest, "???");
                ob = find_object(dest);
                if(!ob) return notify_fail("move: destination unavailable.\n");
        } else
                return notify_fail(sprintf("move: invalid destination %O.\n", dest));

        // Check if the destination ob can hold this object.
        // Beforce checking it, we check if the destination is environment of
        // this_object() (or environmen t of its environment). If it is, then
        // this could be like get something from a bag carried by the player.
        // Since the player can carry the bag, we assume he can carry the this
        // object in the bag and encumbrance checking is unessessary.

        env = this_object();
        thisob = env;
        while(env = environment(env)) if( env==ob ) break;
        if( !env && (int)ob->query_encumbrance() + weight()
                > (int)ob->query_max_encumbrance() ) {
                if( ob==this_player() )
                        return notify_fail( thisob->name() + "对你而言太重了。\n");
                else
                        return notify_fail( thisob->name() + "对" + ob->name() + "而言太重了。\n");
        }

        if( userp(ob) ) {
                sum = sizeof(all_inventory(ob));
                if( sum > MAX_ITEM_SUM ) { 
                        tell_object(ob,YEL"你身上好像放不下这么多东西，还是先存点起来吧。\n"NOR);
                        return 0;
                }
        }
        // Move the object and update encumbrance

        if( env = environment() )
                env->add_encumbrance( - weight());
        move_object(ob);
                ob->add_encumbrance(weight());

        // If we are players, try look where we are.
        if( interactive(thisob)         // are we linkdead?
        &&      living(thisob)                  // are we still concious?
        &&      !silently ) {
                mapping exits;
                string *dirs;
                env = environment();
                exits = env->query("exits");
                
                if( (time() - (int)query_temp("last_move_time")) < 2 ) {
                        tell_object(thisob, HIG +"『"+HIR+env->query("short")+HIG+"』\n"+ NOR);
                } else if( query("env/brief") ) {
                        str = HIG +"『"+HIR+env->query("short")+HIG+"』\n"+ NOR;
                        inv = all_inventory(env);
                        for(i=sizeof(inv)-1; i>=0; i--) {
                                if( inv[i]==thisob ) continue;
                                if( !thisob->visible(inv[i]) ) continue;
                                str += "    " + inv[i]->short() + "\n";
                        }
                        if(exits) dirs = keys(exits);
                        if(sizeof(dirs) > 0) {
                                if( (sizeof(dirs) == 1)
                                && ((int)env->query_door(dirs[0], "status") == DOOR_CLOSED) )
                                        str += NOR"这里没有明显的出口"NOR;
                                else str += NOR"这里明显的出口是："NOR;
                        }
                        for(i=0; i<sizeof(exits); i++) {
                                if( (int)env->query_door(dirs[i], "status") == DOOR_CLOSED ) continue;
                                str += HIG + "  " + dirs[i] + NOR;
                        }
                        str += "\n"NOR;
                        tell_object(thisob, str);
                } else {
                        command("look");
                }
                set_temp("last_move_time", time());
        }
        return 1;
}

void remove(string euid)
{
        object default_ob;

        if( !previous_object()
        ||      base_name(previous_object()) != SIMUL_EFUN_OB )
                error("move: remove() can only be called by destruct() simul efun.\n");

        if( userp(this_object()) && euid!=ROOT_UID ) {
                log_file("destruct", sprintf("%s attempt to destruct user object %s (%s)\n",
                        euid, this_object()->query("id"), ctime(time())));
                error("你(" + euid + ")不能摧毁其他的使用者。\n");
        } else if( this_object()->query("equipped")) {
                if(     !this_object()->unequip() )
                        log_file("destruct", sprintf("Failed to unequip %s when destructed.\n",file_name(this_object())));
        }

        // We only care about our own weight here, since remove() is called once
        // on each destruct(), so our inventory (encumbrance) will be counted as
        // well.
        if( environment() )     environment()->add_encumbrance( - weight );
        if( default_ob = this_object()->query_default_object() )
                default_ob->add("no_clean_up", -1);
}

int move_or_destruct( object dest )
{
        if( userp(this_object()) ) {
                tell_object(this_object(), "一阵时空的扭曲将你传送到另一个地方....\n");
                move(VOID_OB);
        }
}
void move_relic( object dest )
{
        if ( query("equipped") )
                delete( "equipped" );
        move_object( dest );
}

int force_move_to_void()
{
        object ob = find_object(VOID_OB);
        if(!ob) {
                call_other(VOID_OB, "???");
                ob = find_object(VOID_OB);
                if(!ob) return notify_fail("move: destination unavailable.\n");
        }
//        if( environment() ) environment()->add_encumbrance( - weight());
        move_object(ob);
        return 1;
}

