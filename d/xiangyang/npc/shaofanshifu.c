// shaofanshifu.c

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("�շ�ʦ��", ({ "shaofan shifu", "shifu" }));
	set("str", 50);
	set("gender", "����");
	set("age", 18);
	set("long", "���Ǿ���ݳ������շ�ʦ����\n");
	set("combat_exp", 2000);
	set("attitude", "friendly");

	setup();
	carry_object("/clone/misc/cloth")->wear();
}
