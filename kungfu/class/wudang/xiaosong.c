// xiaosong.c ������

inherit NPC;

void create()
{
	set_name("������", ({ "song qingshu", "song" }));
	set("long", 
		"��������Զ�ŵĶ��������顣\n"
		"�������ʮ�꣬�����䵱�������г�����͵����\n");
	set("gender", "����");
	set("age", 20);
	set("attitude", "peaceful");
	set("class", "swordsman");
	set("shen_type", 0);
	set("str", 25);
	set("int", 28);
	set("con", 25);
	set("dex", 25);
	
	set("max_qi", 1000);
	set("max_jing", 500);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 30);
	set("combat_exp", 80000);
	set("score", 10000);

	set_skill("force", 60);
	set_skill("taiji-shengong", 40);
	set_skill("dodge", 70);
	set_skill("tiyunzong", 40);
	set_skill("unarmed", 70);
	set_skill("taiji-quan", 50);
	set_skill("parry", 70);
	set_skill("sword", 70);
	set_skill("taiji-jian", 50);
	set_skill("taoism", 30);
//	set_skill("literate", 40);

	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji-quan");
	map_skill("parry", "taiji-jian");
	map_skill("sword", "taiji-jian");

	create_family("�䵱��", 3, "����");

	setup();
	carry_object("/clone/weapon/changjian")->wield();
}
