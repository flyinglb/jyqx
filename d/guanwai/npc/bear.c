// bear.c
// Date: Sep.22 1997

inherit NPC;
#include <ansi.h>;

void create()
{
        set_name(BLK"����"NOR, ({ "hei xiong", "bear","xiong" }) );
        set("race", "Ұ��");
        set("age", 20);
        set("long", "һֻ���͵ĺ��ܣ�����˶���������С�\n");
        set("attitude", "aggressive");
        set("shen_type", -1);

        set("limbs", ({ "��ͷ", "����", "ǰצ", "��צ" }) );
        set("verbs", ({ "bite", "claw" }) );

        set("combat_exp", 30000);
        set_temp("apply/attack", 150);
        set_temp("apply/defense", 250);
        set_temp("apply/armor", 100);

        setup();

        set("chat_chance", 10);
        set("chat_msg", ({
                "���ܳ�����ҡͷ��β�أ���֪����ʲô��˼��\n",
                "���ܼ��˼����ӣ��������������Ц����ʱһ����š�\n",
        }) );
}

void die()
{
	object ob, corpse;
	message_vision("$N���춯��һ���Һ�������ί���ڵأ����ˣ�\n", this_object());
	if( objectp(corpse = CHAR_D->make_corpse(this_object())) )
	ob = new(__DIR__"xiongdan");
	ob->move(corpse);
	corpse->move(environment(this_object()));
	destruct(this_object());
}
