// woman.c

inherit NPC;

void create()
{
	set_name("Ѿ��", ({ "ya huan","ya","huan"}) );
	set("gender", "Ů��" );
	set("age", 14);
	set("long", "һ�����ܸɵ�Ѿ����\n");
	set("shen_type", 1);
	set("combat_exp", 300);
	set("str", 18);
	set("dex", 18);
	set("con", 18);
	set("int", 19);
	set("attitude", "friendly");
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

