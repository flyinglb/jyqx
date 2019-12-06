// Npc: /u/zqb/tiezhang/npc/hui.c
// Date: zqb 97/06/16

#include <ansi.h>

inherit NPC;

void create()
{
    set_name("���°���", ({
    "huiyi bangzhong",
    "huiyi",
    "bangzhong",
	}));
	set("long",
    "����һ�����н�׳�ĺ��ӣ����۴�׳��������Բ�����������ࡣ\n"
	);

	set("gender", "����");
	set("attitude", "peaceful");

	set("age", 40);
	set("shen_type", -1);
	set("str", 28);
	set("int", 23);
	set("con", 23);
	set("dex", 28);
	set("max_qi", 800);
	set("max_jing", 500);
	set("neili", 800);
	set("max_neili", 800);
	set("jiaji", 80);
	set("combat_exp", 40000);
	set("score", 1);

	set_skill("force", 70);
	set_skill("guiyuan-tunafa", 70);
	set_skill("dodge", 70);
	set_skill("shuishangpiao", 70);
	set_skill("strike", 70);
	set_skill("tiezhang-zhangfa", 70);
	set_skill("parry", 70);

	map_skill("force", "guiyuan-tunafa");
	map_skill("dodge", "shuishangpiao");
	map_skill("strike", "tiezhang-zhangfa");
	map_skill("parry", "tiezhang-zhangfa");

	setup();
	carry_object(__DIR__"obj/black-cloth")->wear();
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
	&& !present("tiezhang ling", ob) 
        && ( (fam = ob->query("family")) && fam["family_name"] != "���ư�" )  
        && (int)ob->query("combat_exp", 1) >= 10000 ) 
	{
		if( !ob->query_temp("warned") ) {
        command("say վס���㲻�����ư���ӣ������ڴ˾�������");
        command("say ʶ��ľͿ�����ǵ�үү���𣬴����Ĺ��ȣ���");
        command("hehe");
			ob->set_temp("warned", 1);
		}
          else if( ob->query_temp("stay") < 3 ) ob->add_temp("stay", 1);
                else {
                	command("say ���ò��ͷ��ˣ����ҵ����ư�����Ұ������\n");
			remove_call_out("hiting_ob");
                     	call_out("hiting_ob", 1, ob);
		}
	}       

}
int hiting_ob(object ob)
{
	object me;
	me=this_object();
	ob->kill_ob(me);
        me->fight_ob(ob);
}

