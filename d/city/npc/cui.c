// cui.c ��Ա��

inherit NPC;

void create()
{
	set_name("��Ա��", ({ "cui yuanwai", "cui" }));
	set("gender", "����");
	set("age", 55);

	set("max_qi",500);
	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_skill("parry", 50);
	set_temp("apply/attack", 40);
	set_temp("apply/defense", 40);
	set_temp("apply/damage", 10);

	set("combat_exp", 25000);
	set("shen_type", -1);
	setup();
	add_money("silver", 5);
	carry_object(__DIR__"obj/yaoshi");
	carry_object("/clone/misc/cloth")->wear();
}
	
