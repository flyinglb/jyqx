// FanYao.c

#include "ansi.h"

inherit NPC;
inherit F_MASTER;
inherit F_UNIQUE;

string ask_me();

void create()
{
	set_name("��ң", ({"fan yao","fan","yao",}));
	set("long",
        "����һλ�������е�ͷ�ӣ����ײ����ۡ�\n"
        "�����������߰˰˵�ȫ���˰̣���ֱ������������Ŀ�ˡ�\n"
	);

	set("title",HIG "����" HIR "������ʹ" NOR);
	set("level",11);
	set("gender", "����");
	set("attitude", "peaceful");
	set("class", "bonze");

	set("age", 38);
	set("shen_type", 1);
	set("per", 12);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("max_qi", 3500);
	set("max_jing", 1500);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 150);
	set("combat_exp", 1000000);
	set("score", 800000);

	set_skill("force", 180);
	set_skill("jiuyang-shengong", 180);
	set_skill("dodge", 180);
	set_skill("lingxu-bu", 180);
	set_skill("finger", 180);
	set_skill("strike", 180);
	set_skill("hand", 180);
	set_skill("claw", 180);
	set_skill("parry", 180);
	set_skill("blade", 180);
	set_skill("jinwu-daofa", 180);
	set_skill("nianhua-zhi", 180);
	set_skill("sanhua-zhang", 180);
	set_skill("fengyun-shou", 180);
	set_skill("longzhua-gong", 180);
	set_skill("buddhism", 100);
	set_skill("literate", 110);

	map_skill("force", "jiuyang-shengong");
	map_skill("dodge", "lingxu-bu");
	map_skill("finger", "nianhua-zhi");
	map_skill("strike", "sanhua-zhang");
	map_skill("hand", "fengyun-shou");
	map_skill("claw", "longzhua-gong");
	map_skill("blade", "jinwu-daofa");
	map_skill("parry", "nianhua-zhi");

	set("inquiry", ([
		"����ʥ����"  : (: ask_me :),
		"����ʥ����"  : (: ask_me :),
		"ʥ����"      : (: ask_me :)
	]));

	set("chat_chance_combat", 20);
	set("chat_msg_combat", ({
		(: prepare_skill("finger", "nianhua-zhi") :),
		(: prepare_skill("strike", "sanhua-zhang") :),
	}) );
	create_family("����",34, "������ʹ");

	setup();

        carry_object("/d/mingjiao/obj/baipao")->wear();
}

void init()
{
	object me,ob;
	me = this_object () ;
	ob = this_player () ;

	::init();

	if( interactive(ob) && !is_fighting() )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, me, ob);
	}
}

void attempt_apprentice(object ob)
{
	command("say �Ҳ���ͽ�ģ����Ҹ�λ����ȥ��");
	return 0;
}

#include "fanyao.h"
