// zhongxiaoer.c

inherit NPC;

void create()
{
	set_name("��С��",({ "zhong xiaoer", "zhong", "xiaoer" }) );
        set("gender", "����" );
        set("age", 3);
        set("long", "�����Ӱ��ĵĶ����ӣ���ֻ�ǹ���׷��˺ҧ����\n");
        set("combat_exp", 50);
//        set("shen", 50);
	set("shen_type", 1);
	set("str", 11);
	set("dex", 11);
	set("con", 11);
	set("int", 11);
        set("attitude", "friendly");
        setup();
	carry_object("/clone/cloth/cloth")->wear();
}

