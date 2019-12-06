// mafu.c ���

inherit NPC;
int do_ride();

void destroy(object obj)
{
        if(!obj) return;
        obj->move(VOID_OB);
        destruct(obj);
}
void create()
{
        set_name("���", ({ "ma fu","ma fu"}));
        set("age", 32);
        set("gender", "����");
        set("long","ѱ��������С�����������Ϳ��Թ͵���\n");
        set("attitude", "peaceful");
        set("str", 24);
        set("dex", 16);
        set("combat_exp", 50000);
        set("shen_type", 1);

        set_skill("unarmed", 60);
        set_skill("dodge", 60);
        set_skill("parry", 60);
        set_skill("force", 60);
        set_temp("apply/attack", 40);
        set_temp("apply/defense", 40);
        set_temp("apply/armor", 30);
        set("chat_chance",2);
        setup();
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
               remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
	add_action("do_rideyz", "rideyz");
	add_action("do_ridelz", "ridelz");
}
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        say( "����ͷ������˵������λ�͹٣����뵽������һƥ����ɣ�\n");
}

int accept_object(object who, object ob)
{
//        object myenv ;
	if (ob->query("money_id") && ob->value() >= 100)
	{
	message_vision("����$N˵���ã���λ"+RANK_D->query_respect(who) +
		"���ھͳ�����? �Ǿ�����ɡ�\n", who);
		this_player()->set_temp("marks/horserent",1);
                    call_out("destroy",1,ob);
 	      	return 1;
	}
	else  
		message_vision("�����ü��$N˵��������Ҳ̫���˰ɣ�\n", who);
	return 1;
}

#include "mafuyz.h"
#include "mafulz.h"
