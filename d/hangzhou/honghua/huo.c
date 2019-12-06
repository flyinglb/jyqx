// huo.c ����ͩ

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("����ͩ", ({ "huo qingtong", "huo","qingtong" }));
	set("long", 
"��Ů��������͸��һ��Ӣ����������ˣ�������������÷��ѩ������
��ޥ��˪���������ڣ�ϼӳ������˫Ŀ���������亮��������ذ�ף�
���洹�磬һ�������ӣ�ͷ����˿���Сñ��ñ�߲���һ��������
������ë�������������续��\n");
	set("nickname", HIG"����"HIY"����"NOR);
	set("gender", "Ů��");
	set("class", "swordsman");
	set("age", 18);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("per", 30);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	
	set("max_qi", 2000);
	set("max_jing", 1000);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 100);
	set("combat_exp", 600000);

	set_skill("literate", 120);
	set_skill("force", 120);
	set_skill("dodge", 120);
	set_skill("parry", 120);
	set_skill("sword", 120);
	set_skill("hand", 120);
	set_skill("claw", 120);
	set_skill("yunlong-xinfa", 120);
	set_skill("yunlong-shengong", 120);
	set_skill("yunlong-jian", 120);
	set_skill("yunlong-shenfa", 120);
	set_skill("yunlong-shou", 120);
	set_skill("yunlong-zhua", 120);

	map_skill("dodge", "yunlong-shenfa");
	map_skill("force", "yunlong-shengong");
	map_skill("hand", "yunlong-shou");
	map_skill("parry", "yunlong-shou");
	map_skill("claw", "yunlong-zhua");
	map_skill("sword", "yunlong-jian");

	prepare_skill("hand","yunlong-shou");
	prepare_skill("claw","yunlong-zhua");
	set("env/wimpy", 60);
	set_temp("is_riding", HIC"������"NOR);
	set("env/wimpy", 40);

 	setup();
	carry_object(__DIR__"obj/cuiyu")->wear();
	carry_object(__DIR__"obj/huangshan")->wear();
	carry_object(__DIR__"obj/shortsword")->wield();
	carry_object(__DIR__"obj/horse");
}

void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	command("ride horse");
}
