//kid.c
inherit NPC;

void create()
{
	set_name("С��",({ "kid" }) );
	set("gender", "����" );
	set("age", 6);
	set("long", "���Ǹ�ũ��С����\n");
	set("combat_exp", 50);
	set("shen_type", 0);
	set("str", 10);
	set("dex", 10);
	set("con", 10);
	set("int", 10);
	set("attitude", "friendly");
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

