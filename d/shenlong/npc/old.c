// old.c
#include <ansi.h>

inherit NPC;

void create()
{
	set_name("����", ({"old man","old","man"}));
	set("title",HIY"������"NOR"����");
	set("long",
	"����һ�����������ߣ�̫��Ѩ���ʣ����۾���������Ȼ�书���ߡ�\n"+
        "Ȼ����ɫ��������һ��������Ů��Ϊ�����ƺ�����ʲô������ʮ�ֿ�����\n");
	set("gender", "����");
	set("attitude", "peaceful");

	set("age", 30+random(50));
	set("shen_type", -1);
	set("str", 35+random(10));
	set("dex", 35+random(10));
	set("max_qi", 1000);
	set("max_jing", 500);
	set("neili", 500);
	set("max_neili", 500);
	set("jiaji", 25+random(25));
	set("combat_exp", 100000+random(100000));

	set_skill("force", 80);
	set_skill("dodge", 80);
	set_skill("unarmed", 80);
	set_skill("parry", 80);
	set_skill("sword", 80);

	setup();
	carry_object("/d/shenlong/obj/xionghuang")->wield();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	object ob;

	::init();

	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 50, ob);
	}
}

void greeting(object ob)
{
	object obj;
        if ( ob && interactive(ob) )
        {
	if (obj = present("usedgao", ob))          
		unconcious();
	}
	return;
}
