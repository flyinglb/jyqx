// yin.c
#include <ansi.h>

inherit NPC;
inherit F_UNIQUE;
inherit F_MASTER;
int do_join(string arg);

void create()
{
	set_name("���", ({ "yin jin", "yin"}));
	set("title", HIY"������"YEL"����ʹ"NOR);
	set("long", "���Ǹ�����, һ������, �����Ǹ�С��.\n" );
	set("gender", "����");
	set("age", 44);
	set("str", 35);
	set("dex", 20);
	set("max_qi",3000);
        set("qi",3000);
	set("max_jing",1000);
        set("jing",1000);
	set("combat_exp", 500000);
	set("score", 20000);
	set("shen_type", -1);
	set("attitude", "peaceful");

	set_skill("force", 80);
	set_skill("dodge", 90);
	set_skill("strike", 90);
	set_skill("claw", 90);
	set_skill("parry", 80);
	set_skill("staff", 80);
	set_skill("literate", 50);
	set_skill("huagong-dafa", 80);
	set_skill("zhaixinggong", 85);
	set_skill("chousui-zhang", 100);
	set_skill("sanyin-wugongzhao", 100);
	set_skill("shenlong-xinfa", 80);
	set_skill("shedao-qigong", 80);

	map_skill("force", "huagong-dafa");
	map_skill("dodge", "zhaixinggong");
	map_skill("claw", "sanyin-wugongzhao");
	map_skill("strike", "chousui-zhang");
	map_skill("parry", "chousui-zhang");
	prepare_skill("claw", "sanyin-wugongzhao");
	prepare_skill("strike", "chousui-zhang");

	create_family("������",2,"����");

	set("neili", 1000); 
	set("max_neili", 1000);
	set("jiali", 100);
        set("inquiry", ([
		"������" :  "һ�������벻���������̵�(join shenlongjiao).\n",
		"���" :  "һ�������벻���������̵�(join shenlongjiao).\n",
		"�鰲ͨ" :  "����Ƣ������,Ҫ�������Ĳźá�\n",
		"����" :  "����Ƣ������,Ҫ�������Ĳźá�\n",
		"�ں�" : "���겻��!�����ɸ�!��������!������ʥ!\n",
       ]) );
	setup();
	carry_object("/clone/misc/cloth")->wear();
	add_money("silver", 10);
}

void init()
{
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {

		remove_call_out("greeting");
		call_out("greeting", 50, ob);
	}
	add_action("do_join","join");
}

void greeting(object ob)
{
	object obj;
        if (interactive(ob))
        {
	if (obj = present("usedgao", ob))          
	   set("combat_exp",100000);
	   set("qi",100);
	   set("jing",100);
	}
	return;
}

void attempt_apprentice(object ob)
{
	command("say �Ҳ���ͽ, ���Ա��! ");
	return;
}
#include "/kungfu/class/shenlong/shenlong.h"; 
