// mujianping.c
#include <ansi.h>

inherit NPC;

void create()
{
	set_name("�彣��", ({"mu jianping", "mu" }));
	set("title",HIY"������"HIR"����ʹ"NOR"���µ���");
	set("long",
	"����������С���������佭�����������̳�����Ů���ӣ�����ʮ�ֽ���������\n"
	);

	set("gender", "����");
	set("attitude", "peaceful");

	set("age", 10+random(10));
	set("shen_type", -1);
	set("str", 25+random(10));
	set("dex", 25+random(10));
	set("max_qi", 200);
	set("max_jing", 150);
	set("neili", 200);
	set("max_neili", 200);
	set("jiaji", 5+random(5));
	set("combat_exp", 20000+random(10000));

	set_skill("force", 40);
	set_skill("dodge", 40);
	set_skill("unarmed", 40);
	set_skill("parry", 40);
	set_skill("sword", 60);
	set_skill("shedao-qigong", 30);
	map_skill("sword","shedao-qigong");

	setup();
	carry_object("/d/shenlong/obj/xionghuang")->wield();
        carry_object("/d/city/obj/duanjian")->wield();
	carry_object("/clone/misc/cloth")->wear();
	add_money("silver",5);
}

void init()
{
	object ob;

	::init();

	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 10, ob);
	}
}

void greeting(object ob)
{
	object obj;
        if (interactive(ob))
        {
	if (obj = present("usedgao", ob))          
		unconcious();
	}
	return;
}
