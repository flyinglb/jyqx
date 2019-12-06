// Npc: /kungfu/class/shaolin/dao-guo.c
// Date: YZC 96/01/19

#include <ansi.h>

inherit NPC;

string ask_me();

void create()
{
	set_name("������ʦ", ({
		"daoguo chanshi",
		"daoguo",
		"chanshi",
	}));
	set("long",
		"����һλ��ĸߴ������ɮ�ˣ����۴�׳��������Բ�����ֱֳ�\n"
		"�У���һϮ�Ҳ�������ģ��ƺ���һ�����ա�\n"
	);


	set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 40);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 400);
	set("max_jing", 300);
	set("neili", 450);
	set("max_neili", 450);
	set("jiali", 40);
	set("combat_exp", 10000);
	set("score", 100);

	set_skill("force", 50);
	set_skill("hunyuan-yiqi", 50);
	set_skill("dodge", 50);
	set_skill("shaolin-shenfa", 50);
	set_skill("strike", 50);
	set_skill("banruo-zhang", 50);
	set_skill("parry", 50);
	set_skill("sword", 50);
	set_skill("damo-jian", 50);
	set_skill("buddhism", 50);
	set_skill("literate", 50);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("strike", "banruo-zhang");
	map_skill("sword", "damo-jian");
	map_skill("parry", "damo-jian");

	prepare_skill("strike", "banruo-zhang");

	create_family("������", 39, "����");

	set("inquiry", ([
		"ľ��"     : (: ask_me :),
		"����"	   : (: ask_me :),
		"��ľ��"   : (: ask_me :)
	]));

	setup();

        carry_object("/d/shaolin/obj/changjian")->wield();
        carry_object("/d/shaolin/obj/dao-cloth")->wear();
}

void init()
{	
	object me, ob;

	me = this_object();

	::init();
	if( objectp(ob = present("mu ren", environment())) )
	{
		remove_call_out("repairing_1");
		call_out("repairing_1", 5, me, ob);
	}
}

int repairing_1(object me, object ob)
{
	if ( !present(ob, environment()) ) return 1; 

	command("say �����ľ�˰ɣ� ���������ƣ� ���ڱ��ϴ��ţ����ܰ���ʲôæ��");
	
	remove_call_out("repairing_2");
	call_out("repairing_2", 2+random(3), me, ob);

	return 1;
}

int repairing_2(object me, object ob)
{
	if ( !present(ob, environment()) ) return 1; 

	if( ob->query("damaged") )
	{
		message_vision(GRN "\n������ʦ����ľ������һ�ᣬ�����Ű⶯ľ�˵���֫���Դ�����������߶��ʲô��\n\n" NOR, me);
		remove_call_out("repairing_3");
		call_out("repairing_3", 2+random(2), me, ob);
	}
	else
	{
		command("say ��ľ�˺ö˶˵���û���� ������Զ�������ҹ�����");
		command("follow none");

		message_vision(GRN "\n������ʦ���Ĺĵ����ˡ�\n" NOR, me);
		me->move("/d/shaolin/guangchang3");

		remove_call_out("do_back");
		call_out("do_back", random(15), me);
	}

	return 1;
}
	
int repairing_3(object me, object ob)
{
	command("say ��ԭ����ˣ��������޿��ɣ�");
	message_vision(GRN "\n�����Ŵӻ����ͳ�һ��ѹ���������ľ�˵����壬��Ū�˼��¡�\n\n" NOR, me);

	remove_call_out("repairing_4");
	call_out("repairing_4", 3+random(3), me, ob);

	return 1;
}

int repairing_4(object me, object ob)
{
	if( random(2) == 0 ) 
	{		
		command("say �ã��޺��ˣ�");
		ob->delete("damaged");
		ob->set("fight_times", 0);	
		message_vision(GRN "\nľ�˵�����֨֨��Ť���˼��£��ָ�������վ������̬��\n\n" NOR, me);
	}
	else 
		message_vision(GRN "\n������ʦ̾�˿�����˵�����������У���ľ���𻵵�̫�����ˣ�û�������ˣ�\n" NOR, me);

	command("say �ã��������ˣ�");
	command("wave");
	command("follow none");

	message_vision(GRN "\n������ʦ���˳�ȥ��\n" NOR, me);
	me->move("/d/shaolin/guangchang3");

	remove_call_out("do_back");
	call_out("do_back", random(15), me);

	return 1;
}

int do_back(object me)
{
	me->move("/d/shaolin/twdian");
	return 1;
}

string ask_me()
{
	mapping fam; 
	object ob;

	ob = this_player();
	
	if (!(fam = ob->query("family")) || fam["family_name"] != "������")
		return RANK_D->query_respect(ob) + 
		"�뱾��������������֪�˻��Ӻ�̸��";

	command("say ľ�˴����ǰɣ� �ðɣ��Ҹ���ȥ������");
	command("follow " + ob->query("id"));

	return "�����߰գ�\n";
}