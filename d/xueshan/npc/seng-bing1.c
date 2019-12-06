//
// /d/xueshan/npc/seng-bing1.c
//

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
                "����һλ��ĸߴ��׳��ɮ�ˣ����۴�׳��������Բ�����ֳ�ɮ\n"
                "������һϮ��ɫ���ģ��ƺ�����һ�����ա�\n"
	);

	set("gender", "����");
	set("attitude", "peaceful");
	set("class", "bonze");

	set("age", 40);
	set("shen_type", -1);
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
	set_skill("xiaowuxiang", 50);
	set_skill("dodge", 50);
	set_skill("shenkong-xing", 50);
	set_skill("unarmed", 50);
	set_skill("yujiamu-quan", 50);
	set_skill("parry", 50);
	set_skill("staff", 50);
	set_skill("xiangmo-chu", 50);

	map_skill("force", "xiaowuxiang");
	map_skill("dodge", "shenkong-xing");
	map_skill("unarmed", "yujiamu-quan");
	map_skill("parry", "xiangmo-chu");
	map_skill("staff", "xiangmo-chu");

	setup();

    carry_object("/d/xueshan/obj/senggun")->wield();
    carry_object("/d/xueshan/obj/b-jiasha")->wear();
}

void init()
{
	object me, ob;
	mapping fam;

	::init();

	ob = this_player();
	me = this_object();
	
	if (interactive(ob) 
        && !wizardp(ob)
	&& !environment(ob)->query("no_fight")
        && ((fam=ob->query("family")) 
        && fam["family_name"]!="ѩɽ��" ))
	{
                if( !ob->query_temp("warned") ) {
                        command("say ����˭����ô����ѩɽ�����ˣ���\n");
			command("say ����������뿪���´ο����������ģ�");
			ob->set_temp("warned", 1);
		}
		else if( ob->query_temp("stay") < 10 ) ob->add_temp("stay", 1);
		else {
                        command("say �󵨿�ͽ�������ɣ�\n");
                        me->set_leader(ob);
			remove_call_out("kill_ob");
			call_out("kill_ob", 1, ob); 
		}
	}

}

