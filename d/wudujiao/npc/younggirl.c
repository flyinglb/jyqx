// younggirl.c  ������Ů
inherit NPC;

void create()
{
	set_name("������Ů", ({ "young girl", "girl" }));
	set("gender", "Ů��");
	set("age", 18);
       set("max_qi",300);
       set("per",35);
	set("long", "һ����������ε�������Ů��\n");
	set("combat_exp", 7000);
	set("shen_type", 1);
       set_skill("unarmed", 30);
       set_skill("dodge", 30);
	setup();
	carry_object("/d/city/obj/cloth")->wear();
}
	
