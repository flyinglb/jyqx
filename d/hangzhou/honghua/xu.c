// xu.c �����

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("�����", ({ "xu tianhong", "xu","tianhong" }));
	set("title", HIR "�컨��"HIG"�ߵ���" NOR);
	set("nickname", HIC "�����" NOR);
	set("long", 
"������İ�С�����Ƕ�ı���Ǻ컨������Ҿ�ʦ���书Ҳ��
�������侲���ء�\n");
	set("gender", "����");
	set("class", "scholar");
	set("age", 27);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("per", 19);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	
	set("max_qi", 1800);
	set("max_jing", 800);
	set("neili", 1100);
	set("max_neili", 1100);
	set("jiali", 100);
	set("combat_exp", 350000);

	set_skill("literate", 100);
	set_skill("force", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("blade", 100);
	set_skill("hand", 100);
	set_skill("claw", 100);
	set_skill("yunlong-shengong", 100);
	set_skill("wuhu-duanmendao", 100);
	set_skill("yunlong-shenfa", 100);
	set_skill("yunlong-shou", 100);
	set_skill("yunlong-zhua", 100);

	map_skill("dodge", "yunlong-shenfa");
	map_skill("force", "yunlong-shengong");
	map_skill("blade", "wuhu-duanmendao");
	map_skill("hand", "yunlong-shou");
	map_skill("parry", "wuhu-duanmendao");
	map_skill("claw", "yunlong-zhua");

	prepare_skill("hand","yunlong-shou");
	prepare_skill("claw","yunlong-zhua");
	set("env/wimpy", 20);

 	setup();
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/gangdao")->wield();
}

