inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("����Ȼ", ({ "yanran"}));
	set("nickname", "HIM"��Ʈ"HIW"ѩ"HIM"ɽׯ��"BLINK+HIR"�︱ׯ����");
	set("long", 
		"������Ʈѩɽׯ���ε�ׯ����ǰ��ׯ�����ˣ�����Ȼ\n"
		"����һ������ɢ���£��Ե��������䣬��������\n"
		"������ɫ����͸�죬�����ݣ��㿴�ſ��Ų��ɵô��ˡ�\n"
	set("gender", "Ů��");
	set("age", 30);
	set("attitude", "friendly");
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	
	set("max_qi", 5000);
	set("max_jing", 3000);
	set("neili", 5000);
	set("max_neili", 5000);
	set("jiali", 100);
	set("combat_exp", 2000000);
	set("score", 500000);

	set_skill("force", 200);
	set_skill("taiji-shengong", 200);
	set_skill("dodge", 150);
	set_skill("tiyunzong", 150);
	set_skill("unarmed", 200);
	set_skill("taiji-quan", 200);
	set_skill("parry", 200);
	set_skill("sword", 200);
	set_skill("taiji-jian", 200);
	set_skill("liangyi-jian", 200);
	set_skill("wudang-jian", 200);
	set_skill("taoism", 150);
	set_skill("literate", 100);

	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji-quan");
	map_skill("parry", "taiji-jian");
	map_skill("sword", "liangyi-jian");

	setup();
	carry_object("/d/wudang/obj/bluecloth")->wear();
	carry_object("/clone/weapon/changjian")->wield();
}
