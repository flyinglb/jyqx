// woman.c

inherit NPC;

void create()
{
	set_name("ũ�Ҹ�Ů", ({ "woman" }) );
	set("gender", "Ů��" );
	set("age", 32);
	set("long", "һ���ܾ����ܸɵ�ũ�Ҹ�Ů��\n");
	set("shen_type", 1);
	set("combat_exp", 1200);
	set("str", 15);
	set("dex", 16);
	set("con", 15);
	set("int", 17);
	set("attitude", "friendly");
	setup();
	carry_object("/clone/misc/cloth")->wear();
	add_money("silver", 5);
}

