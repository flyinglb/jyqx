//wolf2.c
inherit NPC;
void create()
{
        set_name("Ұ��", ({ "wolf", "yelang" }) );
        set("race", "Ұ��");
        set("age", 5);
        set("long", "һƥ����ֱ�������۷����̹���ǡ�\n");
        set("attitude", "aggressive");
        set("str", 26);
        set("cor", 30);
        set("limbs", ({ "ͷ��", "����", "�Ȳ�", "β��",}) );
        set("verbs", ({ "bite" }) );
        set("combat_exp", 500000);
        set("chat_chance",50);
        set_skill("dodge",200);
	set_skill("unarmed",200);
	set_temp("apply/attack", 25);
        set_temp("apply/damage", 20);
        set_temp("apply/armor", 18);
        set_temp("apply/defence",20);
	set("chat_msg", ({
		"\nҰ����һ˫���̵��۾������㣬Ѫ��Ŀ��Ѿ��ſ���\n"
		(: random_move :)
	}) );
        setup();
}
