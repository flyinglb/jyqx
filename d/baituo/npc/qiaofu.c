// woman.c

inherit NPC;

void create()
{
	set_name("�Է�", ({ "qiao fu","qiao","fu" }) );
	set("gender", "����" );
	set("age", 33);
	set("long", "һ���ܽ�׳���Է�\n");
	set("shen_type", 1);
	set("combat_exp", 800);
	set("str", 22);
	set("dex", 18);
	set("con", 18);
	set("int", 18);
	set("attitude", "friendly");
	setup();
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/d/baituo/obj/chai");
	carry_object("/d/baituo/obj/chaidao")->wield();
}

