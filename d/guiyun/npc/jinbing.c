// jinbing.c

inherit NPC;

void create()
{
	set_name("����", ({ "jin bing", "bing" }));
	set("gender", "����");
	set("age", 25);
	set("long", "��Щ�󺺸������������������⽡��\n");
	set("combat_exp", 40000);
        set_skill("dodge", 50);
        set_skill("unarmed", 50);
        set_temp("apply/attack",  50);
        set_temp("apply/defense", 50);
	set("shen_type", 1);
	setup();

	add_money("silver",3);
	carry_object("/clone/misc/cloth")->wear();
}


