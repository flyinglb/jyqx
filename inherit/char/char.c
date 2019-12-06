// char.c
// Modified by Eatdami@MX (10/01/2000)
//modified by long

#include <login.h>
#include <action.h>
#include <ansi.h>
#include <command.h>
#include <condition.h>
#include <dbase.h>
#include <move.h>
#include <name.h>
#include <skill.h>
#include <team.h>
#include <user.h>

inherit F_ACTION;
inherit F_ALIAS;
inherit F_APPRENTICE;
inherit F_ATTACK;
inherit F_ATTRIBUTE;
inherit F_COMMAND;
inherit F_CONDITION;
inherit F_DAMAGE;
inherit F_DBASE;
inherit F_EDIT;
inherit F_FINANCE;
inherit F_MESSAGE;
inherit F_MORE;
inherit F_MOVE;
inherit F_NAME;
inherit F_SKILL;
inherit F_TEAM;

// Use a tick with longer period than heart beat to save cpu's work
nosave int tick;

void create()
{
        seteuid(0); // so LOGIN_D can export uid to us
}

// Use this function to identify if an object is a character.
int is_character() { return 1; }
// setup: used to configure attributes that aren't known by this_object()
// at create() time such as living_name (and so can't be done in create()).
void setup()
{
        seteuid(getuid(this_object()));

        set_heart_beat(1);
        tick = 5 + random(10);
        enable_player();
        CHAR_D->setup_char( this_object() );
}

void heart_beat()
{
        int wimpy_ratio, cnd_flag;
        mapping my;
        object ob,env,me;

	if( !(env = environment()) )
                return;

	me = this_object();

        my = query_entire_dbase();

        // If we are dying because of mortal wounds?
        if( my["eff_qi"] < 0 || my["eff_jing"] < 0) {
                remove_all_enemy();
                die();
                return;
        }

        // If we're dying or falling unconcious?
        if( my["qi"] < 0 || my["jing"] < 0) {
                remove_all_enemy();
                if( !living(me) ) die();
                else unconcious();
                return;
        }

        // Do attack if we are fighting.
        if( is_busy() ) {
                continue_action();
                // We don't want heart beat be halt eventually, so return here.
                return;
        } else {
                // Is it time to flee?
                if( is_fighting()
                &&      intp(wimpy_ratio = (int)query("env/wimpy"))
                &&      wimpy_ratio > 0
                &&      (       my["qi"] * 100 / my["max_qi"] <= wimpy_ratio
                        ||      my["jing"] * 100 / my["max_jing"] <= wimpy_ratio) )
                        GO_CMD->do_flee(me);
                // Do attack or clean up enemy if we have fleed.
                attack();
        }

        if( !userp(me) ) {
                me->chat();
                // chat() may do anything -- include destruct(this_object())
                if( !me ) return;
        }

        if( living(this_object()) 
        && query_temp("block_msg/all") > 0 
        && !query("hunmi")
        && me->query("prison/release_time") < 1 ) {
//                set("hunmi",0);
                set_temp("block_msg/all",0);
        }

        if( tick--  ) return;
        else tick = 5 + random(10);

	if (!env->is_chatting_room())
        cnd_flag = update_condition();

        // If we are compeletely in peace, turn off heart beat.
        // heal_up() must be called prior to other two to make sure it is called

        // because the && operator is lazy :P

/*
        //Modify By Byp@MX  ChatRoom's Bug
        //Note: 聊天房间应该只不更新年龄，发呆不断线，和不减食物饮水
        //      暂时先这样吧。
        if( env->is_chatting_room() ) return; 

*/
        if( ((cnd_flag & CND_NO_HEAL_UP) || !heal_up())
        &&      !is_fighting()
        &&      !interactive(me)) {
                if( env ) {
                        ob = first_inventory(env);
                        while(ob && !interactive(ob))
                                ob = next_inventory(ob);
                }
                if( !ob ) set_heart_beat(0);
        }

        if( !interactive(me) ) return;

        // Make us a bit older. Only player's update_age is defined.
        // Note: update_age() is no need to be called every heart_beat, it
        //       remember how much time has passed since last call.
        me->update_age();

        if(query_idle(me) > IDLE_TIMEOUT && !wizardp(me))
                me->user_dump(DUMP_IDLE);
}

int visible(object ob)
{
        int lvl, invis;

        if (!userp(this_object())) return 1;
        if( !wizardp(ob) && !ob->is_ghost() ) return 1;

        lvl = wiz_level(this_object());

        if( lvl > wiz_level(ob) ) return 1;
        invis = (int)ob->query("env/invisibility");
        if( intp(invis) && (invis > lvl) && wizardp(ob) ) return 0;

        if( ob->is_ghost() ) {
                if( is_ghost() ) {
                        if( at_domain(this_object(),1) != "death" ) {
                                tell_object(this_object(),
                                        HIW"牛头马面"HIB"突然出现在一阵烟雾中\n"NOR
                                        HIW"马面"HIB"对你喝到：“大胆小鬼！居然敢留恋阳间，还不快快跟我回去！”\n"NOR
                                        HIW"牛头"HIB"二话不说将招魂棒往你头上一点，你只觉得被一片冷雾包围 ……\n\n\n"NOR);
                                message("vision","不知为什么你忽的打了个冷战。\n",environment(),this_object());
                                move(DEATH_ROOM);
                        }
                        return 1;
                }

                if( query_temp("apply/astral_vision") ) return 1;
                return 0;
        }
        return 1;
}
