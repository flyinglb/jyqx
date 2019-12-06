// WeiYiXiao.c
// pal 1997.05.10

#include "ansi.h"

inherit NPC;
inherit F_MASTER;
inherit F_UNIQUE;

void create()
{
	set_name("ΤһЦ", ({"wei yixiao", "wei", "yixiao",}));
	set("long",
		"�����û�����һֻ���������\n"
		"������ɫ�����˵ġ�\n"
	);

	set("title",HIG "����" HIC "��������" NOR);
	set("level",9);
	set("gender", "����");
	set("attitude", "peaceful");

	set("age", 48);
	set("shen_type", 1);
	set("per", 19);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("max_qi", 3000);
	set("max_jing", 1500);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 150);

	set("combat_exp", 800000);
	set("score", 1000000);

	set_skill("force", 150);
    	set_skill("dodge", 250);
    	set_skill("strike", 180);
	set_skill("sword", 150);
	set_skill("parry", 150);
    	set_skill("jiuyang-shengong", 150);
      	set_skill("qingfu-shenfa", 250);
      	set_skill("hanbing-mianzhang", 180);
      	set_skill("literate", 100);

    	map_skill("force", "jiuyang-shengong");
    	map_skill("dodge", "qingfu-shenfa");
    	map_skill("strike", "hanbing-mianzhang");
    	map_skill("parry", "hanbing-mianzhang");

	prepare_skill("strike","hanbing-mianzhang");

	set("chat_chance_combat", 20);
	set("chat_msg_combat", ({
		(: command("perform xixueqingfu") :),
	}) );
	create_family("����",34, "����");
	setup();

        carry_object("/d/mingjiao/obj/baipao")->wear();
}

void init()
{
	object me,ob;
	me = this_object () ;
	ob = this_player () ;

	::init();

	if (interactive(this_player()) && this_player()->query_temp("fighting"))
	{
		COMBAT_D->do_attack(this_object(), this_player(), query_temp("weapon") );
		this_player()->add_temp("beat_count", 1);
	}       
	if( interactive(ob) && !is_fighting() )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, me, ob);
	}
}

#include "fawang.h"
