// keshang.c

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("ʢƤ�޿���", ({ "ke shang", "shang" }) );
	set("gender", "����" );
	set("age", 32);
	set("long","����һλ��ӡ�����Ŀ��̣�Ƥ����ڣ��ײ���ͷ�������ӡ���˽���ʢƤ�ޡ�\n");
	set("combat_exp", 7000);
        set("str", 17);
        set("dex", 25);
        set("con", 17);
        set("int", 22);
	set("attitude", "friendly");
	setup();
	carry_object("/clone/cloth/cloth")->wear();
	add_money("silver", 10);
}

