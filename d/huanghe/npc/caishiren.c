// caishiren.c

inherit NPC;

void create()
{
	set_name("��ʯ��", ({ "caishi ren","ren" }));
	set("gender", "����");
	set("age", 22);
	set("str", 25);
	set("dex", 16);
	set("per", 20);
	set("long", "����һ����׳���ӡ�\n");
	set("combat_exp", 6000);
	set("shen_type", 1);
	set("attitude", "peaceful");

	setup();
	carry_object(__DIR__"obj/tieqiao")->wield();
	carry_object("/clone/misc/cloth")->wear();
}

