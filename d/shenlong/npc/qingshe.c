//qingshe.c

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("��Ҷ����", ({ "qing she", "she" }) );
	set("race", "Ұ��");
	set("age", 2);
	set("long", "һֻ���˿�����Ƥ������Ҷ���ߡ�\n");
	set("attitude", "peaceful");
	set("str", 20);
	set("cor", 20);
	set("limbs", ({ "ͷ��", "����", "�ߴ�", "β��" }) );
	set("verbs", ({ "bite" }) );

	set("combat_exp", 3000+random(300));

	set_temp("apply/attack", 18);
	set_temp("apply/damage", 15);
	set_temp("apply/armor", 12);
	set_temp("apply/defence",16);

	setup();
}

void init()
{
        object ob;
        ::init();
        if (interactive(this_player()))
        {
	if (!(ob = present("xionghuang", this_player())))          
	{        
                remove_call_out("kill_ob");
                        call_out("kill_ob", 1, this_player());
        }
	}
}

void die()
{
	object ob;
	message_vision("$N���ڵ��ϣ����ˣ�\n", this_object());
	ob = new("/d/baituo/obj/qingdan");
	ob->move(environment(this_object()));
	destruct(this_object());
}

int hit_ob(object me, object ob, int damage)
{
    if ((int)ob->query("combat_exp") > 10000) return 1 ;
	if( random(damage) > (int)ob->query_temp("apply/armor")
	&&	(int)ob->query_condition("snake_poison") < 10 ) {
		ob->apply_condition("snake_poison", 20);
        tell_object(ob, HIG "����ñ�ҧ�еĵط�һ����ľ��\n" NOR );
	}
}
