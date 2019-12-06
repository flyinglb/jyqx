// qi.c
inherit NPC;

void create()
{
	set_name("��Ԫ��", ({ "qi yuankai", "qi" }));
	set("long", "��������ݳ���ȴ�������Ѱ�, �ƺ���������ҵ��\n");
	set("gender", "����");
	set("age", 35);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 30);
	set("int", 40);
	set("con", 30);
	set("dex", 30);
	
	set("max_qi", 500);
	set("max_jing", 500);
	set("neili", 500);
	set("max_neili", 500);
	set("jiali", 50);
	set("combat_exp", 50000);
	set("score", 5000);

	set_skill("huashan-zhangfa", 70);
	set_skill("unarmed",80);
	set_skill("force", 80);
	set_skill("dodge", 80);
	set_skill("parry", 80);
	set_skill("sword", 80);

	map_skill("unarmed", "huashan-zhangfa");
	map_skill("parry", "huashan-zhangfa");

	set("env/wimpy", 60);
	set("inquiry", ([
		"��ʮ���¾�": "�ף���Ҳ֪�������������б��飿\n",
		"��": "�ף���Ҳ֪��������������...��\n",
		"Կ��" : "�ף���Ҳ֪��ȡ��Ҫ��Կ�ף�\n",
	]) );
	set("chat_chance", 1);
	set("chat_msg", ({
		"��Ԫ����Ȼ˵: ����ȡ�����Ҿ��ߡ�\n",
		"��Ԫ��һҧ����˵��: ������̫̰�ˣ��³�֮��һ��ɱ������ڡ�\n",
		"��Ԫ�����������: ���У�ֻ�»��л��ء�\n",
	}) );
	setup();
	carry_object("/clone/misc/cloth")->wear();
	add_money("gold",1);
}

