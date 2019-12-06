// feng.c

inherit NPC;

void create()
{
	set_name("������", ({ "feng zhengdong", "feng" }));
	set("title", "����֪��");
	set("gender", "����");
	set("age", 43);
	set("str", 20);
	set("dex", 20);
	set("long", "�����Ƿ���������������֪����\n");
	set("combat_exp", 30000);
	set("shen_type", 0);
	set("attitude", "heroism");

	set_skill("unarmed", 50);
	set_skill("force", 50);
	set_skill("sword", 50);
	set_skill("dodge", 50);
	set_skill("parry", 50);
	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/armor", 50);
	set_temp("apply/damage", 15);

	set("neili", 500); 
	set("max_neili", 500);
	set("jiali", 10);

	setup();
	carry_object("/clone/weapon/gangjian")->wield();
	carry_object("/clone/misc/cloth")->wear();
}
