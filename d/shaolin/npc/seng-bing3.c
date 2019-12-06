// Npc: /d/shaolin/npc/seng-bing3.c
// Date: YZC 96/01/19

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("����ɮ��", ({
		"seng bing",
		"seng",
		"bing",
	}));
	set("long",
		"����һλ��ĸߴ��׳��ɮ�ˣ����۴�׳��������Բ�����ֱֳ�\n"
		"�У���һϮ�Ҳ�������ģ��ƺ���һ�����ա�\n"
	);

	set("gender", "����");
	set("attitude", "peaceful");
	set("class", "bonze");

	set("age", 40);
	set("shen_type", 1);
	set("str", 25);
	set("int", 20);
	set("con", 20);
	set("dex", 25);
	set("max_qi", 500);
	set("max_jing", 300);
	set("neili", 500);
	set("max_neili", 500);
	set("jiaji", 50);
	set("combat_exp", 10000);
	set("score", 1);

	set_skill("force", 50);
	set_skill("hunyuan-yiqi", 50);
	set_skill("dodge", 50);
	set_skill("shaolin-shenfa", 50);
	set_skill("unarmed", 50);
	set_skill("banruo-zhang", 50);
	set_skill("parry", 50);
	set_skill("blade", 50);
	set_skill("cibei-dao", 50);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("unarmed", "banruo-zhang");
	map_skill("parry", "cibei-dao");
	map_skill("blade", "cibei-dao");

	setup();

	carry_object(__DIR__"obj/jiedao")->wield();
	carry_object(__DIR__"obj/cloth")->wield();
}

void init()
{
	object me, ob;
	mapping fam;

	::init();

	ob = this_player();
	me = this_object();
	
	if (interactive(ob) 
	&& !environment(ob)->query("no_fight")
	&& !present("yingxiong ling", ob) 
	&& ( (fam = ob->query("family")) && fam["family_name"] != "������" ) )
	{
		if( !ob->query_temp("warned") ) {
			command("say ����˭��  ��ô���������������ˣ���");
			command("say ����������뿪���´ο����������ģ�");
			ob->set_temp("warned", 1);
		}
		else if( ob->query_temp("stay") < 10 ) ob->add_temp("stay", 1);
		else {
			command("say �󵨿�ͽ�����Ҵ���������������Ұ������\n");
			me->set_leader(ob);
			remove_call_out("kill_ob");
			call_out("kill_ob", 1, ob); 
		}
	}       

}
