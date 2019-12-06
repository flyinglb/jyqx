// YinTianZheng.c
// pal 1997.05.09

#include "ansi.h"

inherit NPC;
inherit F_MASTER;
inherit F_UNIQUE;

void create()
{
	set_name("������", ({"yin tianzheng", "yin", "tianzheng", }));
	set("long",
        "����һλ��Ŀ����ͺ���ߣ���һ����ɫ���ۡ�\n"
        "����üʤѩ�������۽ǣ����ӹ���������ӥ�졣\n"
	);
                                                          
	set("title",HIG "����" HIW "��üӥ��" NOR);
	set("level",9);
	set("gender", "����");
	set("attitude", "peaceful");

	set("age", 72);
	set("shen_type", 1);
	set("per", 22);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("qi", 3500);
	set("max_qi", 3500);
	set("jing", 1500);
	set("max_jing", 1500);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 150);
	set("combat_exp", 900000);
	set("score", 1000000);

	set_skill("force", 180);
	set_skill("dodge", 120);
	set_skill("unarmed", 185);
	set_skill("parry", 120);
	set_skill("claw", 185);
	set_skill("blade", 160);
	set_skill("jinwu-daofa", 160);
//	set_skill("hand", 185);
	set_skill("literate", 60);
	set_skill("jiuyang-shengong", 180);
	set_skill("xiaoyaoyou", 120);
	set_skill("sougu", 185);
	set_skill("longzhua-gong", 140);

	map_skill("force", "jiuyang-shengong");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("claw", "sougu");
	map_skill("parry", "longzhua-gong");
	map_skill("blade", "jinwu-daofa");

	prepare_skill("claw", "sougu");

	set("chat_chance_combat", 20);
	set("chat_msg_combat", ({
		(: command("perform muyeyingyang") :),
	}) );
	create_family("����",34, "����");
	setup();

	carry_object("/d/mingjiao/obj/baipao")->wear();
	carry_object("/clone/weapon/gangdao")->wield();
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
