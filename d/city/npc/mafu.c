// mafu.c ���

inherit NPC;
#include <ansi.h>
int do_ride();
void destroy(object obj)
{
        if(!obj) return;
        obj->move(VOID_OB);
        destruct(obj);
}


void create()
{
        set_name("���", ({ "ma fu","mafu"}));
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
	add_action("do_ridebj", "ridebj");
	add_action("do_ridesz", "ridesz");
	add_action("do_ridehz", "ridehz");
	add_action("do_ridefz", "ridefz");
	add_action("do_ridedl", "ridedl");
	add_action("do_rideyd", "rideyd");
	add_action("do_rideyl", "rideyl");
	add_action("do_ridefs", "ridefs");
	add_action("do_rideem", "rideem");
	add_action("do_ridexy", "ridexy");
}
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        say( "����ͷ������˵������λ�͹٣����뵽������һƥ����ɣ�\n");
}

int accept_object(object who, object ob)
{
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
        call_out("destroy",1,ob);
	return 1;
}

#include "mafubj.h"
#include "mafusz.h"
#include "mafuhz.h"
#include "mafufz.h"
#include "mafufs.h"
#include "mafudl.h"
#include "mafuyd.h"
#include "mafuyl.h"
#include "mafuem.h"
#include "mafuxy.h"
