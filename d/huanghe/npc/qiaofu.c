// qiaofu.c

inherit NPC;

void create()
{
	set_name("�Է�", ({ "qiao fu","fu" }));
	set("gender", "����");
	set("age", 52);
	set("str", 25);
	set("dex", 16);
	set("per", 21);
	set("long", "����һ����׳�Ϻ���\n");
	set("combat_exp", 5000);
	set("shen_type", 1);
	set("attitude", "peaceful");

	setup();
	carry_object(__DIR__"obj/futou")->wield();
	carry_object("/clone/misc/cloth")->wear();
}

