// this npc will duplicate anyone who he/she lost his fight to....
#include <ansi.h>
#define CHAMPION_FILE "/clone/npc/bhzhu.o"
inherit NPC;
void loadall(object me);
int changeshape(object winner);
int brag();
void create()
{
	string info,name,id,file;
        set_name( "�׻�����" , ({ "tangzhu" }) );
        set("chat_chance", 10);
        set("chat_msg", ({
                (: brag :),
        }) );
	setup();
	info = read_file(CHAMPION_FILE);
	if( info && sscanf(info,"%s %s %s",file,id,name) == 3)
	{
		restore_object(file);
        set_name( name , ({ id }) );
        delete("env");
        set("attitude", "aggressive");
        reset_action();
        delete_temp("already_loaded");
        loadall(this_object());
        set("title", HIR "�׻�������" NOR);
	}
	setup();	
		
}
void lose_enemy(object winner)
{
	call_out("changeshape",2,winner);
	return;
}
void changeshape( object winner)
{
	string winner_file;
	string name,id;
	if(!stringp(winner_file = winner->query_save_file()))
	return;
        CHANNEL_D->do_channel(this_object(), "chat",
        sprintf( "%s�����ڿ�ʼ�����ǰ׻��õ��������ˣ��� \n",
        winner->name(1)));
	seteuid(ROOT_UID);
	write_file(CHAMPION_FILE,sprintf("%s %s %s",
	winner_file,winner->query("id"),winner->query("name")),1);
	seteuid(getuid());
	restore_object(winner_file);
	name = winner->query("name");
	id = winner->query("id");
	set_name( name , ({ id }) );
	delete("env");
	set("attitude", "aggressive");
	reset_action();
	delete_temp("already_loaded");
	loadall(this_object());	
	set("title", HIR "�׻�������" NOR);	
	return ;
}

void loadall(object me)
{
        int MAX = 3;
        string name,id, *created;
        int i,j;
        object thing, *inv;
	inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++)
                {
                        destruct(inv[i]);
                }

        id = me->query("id");
        created = get_dir(DATA_DIR + "login/" + id[0..0] + "/" + id + "/");
        for(j=0; (j<sizeof(created) && j < (MAX+1) ); j++)
        if( sscanf(created[j], "%s.c", name) == 1 )
                {
	thing = new( DATA_DIR + "login/" + id[0..0] + "/" + id +
 	"/" + name + ".c");
                        if(thing->move(me)) 
			{
			thing->wield();
			thing->wear();
			} 
                }
	me->reset_action();
        me->set_temp("already_loaded",1);
}
void init()
{
	if(!query_temp("already_loaded"))
		loadall(this_object());
	return;
}
int accept_fight(object me)
{
	return 1;
}
int brag()
{
        CHANNEL_D->do_channel(this_object(), "say",
        "�Ҿ��ǰ׻��õ������������ҵ�λ�þ������ԣ�\n");
        return 1;
}
void die()
{
        object ob;

        if( !ob = query_temp("last_damage_from") )
                ob = this_player(1);

        if( !ob ) return;

	changeshape(ob);
	return;
}
