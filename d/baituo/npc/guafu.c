// guafu.c

inherit NPC;

void create()
{
	set_name("�Ѹ�", ({ "guafu" }) );
	set("gender", "Ů��" );
	set("age", 25);
	set("long", "һ������Ư���ֲ��ʼ�į��С�Ѹ���\n");
	set("shen_type", -1);
	set("combat_exp", 10000);
	set("str", 18);
	set("dex", 19);
	set("con", 19);
	set("int", 19);
	set("attitude", "friendly");
	set("chat_chance",20);
	set("chat_msg",({
	    "С�Ѹ����ţ��ҿ����ķ��ۣ�����ôƲ���Ҳ�����Ӵ��\n",
	    "С�Ѹ�Ĩ�˰����ᣬ���������һ�ۡ�\n",
	   }) );
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

