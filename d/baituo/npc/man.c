// man.c

inherit NPC;

void create()
{
	set_name("ũ��", ({ "man" }) );
	set("gender", "����" );
	set("age", 29);
	set("long", "һ���ܽ�׳��׳��ũ��\n");
	set("shen_type", 1);
	set("combat_exp", 2000);
	set("str", 20);
	set("dex", 18);
	set("con", 18);
	set("int", 18);
	set("attitude", "friendly");
	setup();
	carry_object("/clone/misc/cloth")->wear();
	add_money("silver", 10);
}

