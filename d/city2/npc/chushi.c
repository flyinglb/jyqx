// chushi.c
inherit NPC;

void create()
{
	set_name("��ʦ", ({ "chu shi", "chu" }));
	set("gender", "����");
	set("age", 45);

	set("combat_exp", 7500);
        set_skill("unarmed", 35);
        set_skill("force", 35);
        set_skill("dodge", 40);
        set_temp("apply/attack", 30);
        set_temp("apply/defense", 40);
	set("shen_type", -1);
	setup();
	carry_object("/d/city/obj/cloth")->wield();

}
	
