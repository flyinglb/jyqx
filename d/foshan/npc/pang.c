// pang.c

inherit NPC;

void create()
{
	set_name("������", ({ "pang shangren", "pang" }));
	set("gender", "����");
	set("age", 43);
	set("long", "���ʷ����ֵģ�һ�������ࡣ\n");
	set("combat_exp", 2000);
        set_skill("dodge", 20);
        set_skill("unarmed", 20);
        set_temp("apply/attack",  10);
        set_temp("apply/defense", 10);
	set("shen_type", 0);
	setup();

	add_money("silver",3);
	carry_object(__DIR__"obj/magcloth")->wear();
}

