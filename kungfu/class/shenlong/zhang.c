// zhang.c
#include <ansi.h>

inherit NPC;
inherit F_UNIQUE;
inherit F_MASTER;
int do_join(string arg);

void create()
{
	set_name("�ŵ���", ({ "zhang danyue", "zhang"}));
	set("title", HIY"������"BLU"����ʹ"NOR);
	set("long", "����һ�����´�, ��ɫ���, ���ӷ���, �ƺ��־��Ѽ�.\n" );
	set("gender", "����");
	set("age", 44);
	set("str", 35);
	set("dex", 20);
	set("max_qi",3000);
        set("qi",3000);
	set("max_jing",1000);
        set("jing",1000);
	set("combat_exp", 500000);
	set("score", 40000);
	set("shen_type", -1);
	set("attitude", "peaceful");

	set_skill("force", 90);
	set_skill("huntian-qigong", 85);
	set_skill("dodge", 90);
	set_skill("xiaoyaoyou", 85);
	set_skill("unarmed", 85);
	set_skill("xianglong-zhang", 85);
	set_skill("shedao-qigong", 90);
	set_skill("shenlong-xinfa", 90);
	set_skill("parry", 70);
	set_skill("staff", 90);
	set_skill("literate", 70);

	map_skill("force", "shenlong-xinfa");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("unarmed", "xianglong-zhang");
	map_skill("parry", "xianglong-zhang");

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
        ob = this_player();
        if( interactive(ob) && !is_fighting() ) {

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
	command("say ���߿�! ����! ");
	return;
}
#include "/kungfu/class/shenlong/shenlong.h"; 
