// lama.c
#include <ansi.h>

inherit NPC;

void create()
{
	set_name("����", ({"lama"}));
	set("long",
	"����һ���ߴ�������۴�׳��������Բ���ƺ�����������ʿ��\n"
	);

	set("gender", "����");
	set("attitude", "aggressive");
	set("class", "bonze");

	set("age", 20+random(30));
	set("shen_type", -1);
	set("str", 25+random(10));
	set("dex", 25+random(10));
	set("max_qi", 500);
	set("max_jing", 300);
	set("neili", 1500);
	set("max_neili", 1500);
	set("jiaji", 50+random(50));
	set("combat_exp", 50000);
	set("score", 1);

	set_skill("force", 70);
	set_skill("dodge", 70);
	set_skill("unarmed", 70);
	set_skill("parry", 70);
	set_skill("blade", 70);

	setup();

	carry_object("/d/shaolin/obj/jiedao")->wield();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        object ob = this_player();

        if( ob && interactive(ob) ) {
                ::init();
                remove_call_out("greeting");
                call_out("greeting", 1, this_player());
        }
}

void greeting(object ob)
{
	object me;
	me = this_object();

	if(ob->query_temp("hastrystab")==6) return;	
	if (interactive(ob) 
	&& !environment(ob)->query("no_fight"))
	{
		if( !ob->query_temp("warned2") ) {
		if(ob->query_temp("hastrystab")) 
		command("say �������ˣ����Ȼ�������ֵܣ�");
		else
		command("say ����˭����Ȼ���ƻ���ү�ĺ��£���������ǲ��ǣ���");
		ob->set_temp("warned2", 1);
		}
		else {
			if(ob->query_temp("hastrystab")) 
			command("say ��...��..һ��Ҫɱ�����ⱳ��ͱ�˵Ľ������࣡");
			else
			command("say ����һﲻҪ�ܣ��÷�ү�������㣡����\n");
			me->set_leader(ob);
			remove_call_out("kill_ob");
			call_out("kill_ob", 1, ob); 
		}
	}       

}
