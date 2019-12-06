// wugeng.c
#include <ansi.h>
inherit NPC;

void create()
{
	set_name("�޸�����", ( { "wugen daozhang", "wugen","daozhang" }) );
	set("title", HIY"������"HIR"����ʹ"NOR);
	set("gender", "����" );
	set("age", 55);
	set("long",
	      "���Ǹ���ʮ����ĺ������,��ò����,�����Դ�ɱ����\n"
	     );

	set("int", 30);
	set("str", 25);
	set("con", 25);
	set("dex", 25);

	set("qi", 3000);
	set("max_qi", 3000);
	set("jing", 1000);
	set("max_jing", 1000);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 100);
	set("combat_exp", 500000);
	set("score", 15000);
	set_temp("apply/attack", 60);
	set_temp("apply/defense", 60);
	set_temp("apply/damage", 40);

	set_skill("unarmed",90);
	set_skill("force", 90);
	set_skill("dodge", 90);
	set_skill("parry", 90);
	set_skill("sword", 100);
	set_skill("staff", 100);
	set_skill("literate", 80);
	set_skill("huashan-zhangfa", 60);
	set_skill("huashan-shenfa",80);
	set_skill("huashan-jianfa", 90);
	set_skill("zixia-shengong", 80);
	set_skill("shenlong-xinfa", 90);
	set_skill("shedao-qigong", 90);

	map_skill("force", "zixia-shengong");
	map_skill("unarmed", "huashan-zhangfa");
	map_skill("dodge", "huashan-shenfa");
	map_skill("parry", "huashan-jianfa");
	map_skill("sword", "huashan-jianfa");

	create_family("������",2,"����");

	set("inquiry", ([
		"������" :  "\nһ�������벻���������̵�(join shenlongjiao).\n",
		"�鰲ͨ" :  "\n����Ƣ������,Ҫ�������Ĳźá�\n",
		"����" :  "\n����Ƣ������,Ҫ�������Ĳźá�\n",
		"���" :  "\nһ�������벻���������̵�(join shenlongjiao).\n",
		"�ں�" : "\n���겻��!�����ɸ�!��������!������ʥ!\n",
	]));
	setup();
        carry_object("/d/city/obj/duanjian")->wield();
	add_money("silver",10);
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
        if ( objectp(ob) && interactive(ob) )
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
        command("say �Ҳ���ͽ!");
	return;
}
#include "/kungfu/class/shenlong/shenlong.h"; 
