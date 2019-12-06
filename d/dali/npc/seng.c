// seng.c
inherit NPC;

void create()
{
	set_name("ɮ��", ({"seng ren","seng"}));
	set("long", "һ����׳ɮ�ˡ�\n" );
	set("gender", "����");
	set("attitude", "peace");
	set("class", "bonze");

	set("age", 37);
	set("shen_type", 1);
	set("str", 25);
	set("int", 20);
	set("con", 20);
	set("dex", 25);
	set("max_qi", 500);
	set("max_jing", 100);
	set("neili", 500);
	set("max_neili", 500);
	set("jiali", 100);
	set("combat_exp", 20000);
	set("score", 100);
	set("apply/attack",  30);
	set("apply/defense", 30);

	set_skill("force", 50);
	set_skill("unarmed", 50);
	set_skill("blade", 50);
	set_skill("dodge", 50);
	set_skill("parry", 50);

	setup();
	carry_object("/d/shaolin/obj/cheng-cloth")->wear();
	add_money("silver", 50);
}

