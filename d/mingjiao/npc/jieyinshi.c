// JieYinShi
// pal 1997.05.11

#include "ansi.h"

inherit NPC;
inherit F_UNIQUE;

string ask_for_join();

void create()
{
	set_name("����ʹ", ({"jieyin shi","jieyin","shi",}));
	set("long",
		"����һλ�����������ˣ���һ���ײ����ۡ�\n"
		"���������´������㡣\n"
		);

	set("title", HIG "����" NOR);

	set("gender", "����");
	set("attitude", "friendly");

	set("inquiry",([
		"����"	: (: ask_for_join :),
		]));

	set("age", 30);
	set("shen_type", 1);
	set("str", 25);
	set("int", 17);
	set("con", 50);
	set("dex", 21);
	set("max_qi", 450);
	set("max_jing", 200);
	set("neili", 350);
	set("max_neili", 350);
	set("jiali", 30);
	set("combat_exp", 5000);
	set("score", 100);

	set_skill("force", 30);
	set_skill("hunyuan-yiqi", 30);
	set_skill("dodge", 50);
	set_skill("shaolin-shenfa", 50);
	set_skill("cuff", 50);
	set_skill("jingang-quan", 50);
	set_skill("parry", 30);
	set_skill("buddhism", 30);
	set_skill("literate", 30);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("cuff", "jingang-quan");
	map_skill("parry", "jingang-quan");

	prepare_skill("cuff", "jingang-quan");

	setup();

        carry_object("/d/mingjiao/obj/baipao")->wear();
}


void init()
{
	::init();
}

string ask_for_join()
{
	return "�н����žͿ��Լ��������̡�\n";
}

int accept_object(object ob, object obj)
{
	object me ;
	string men ;
	mapping party;

	me = this_object () ;
	ob = this_player () ;

	if (obj->query("id") == "tuijian xin1" && ob->query_temp("have_letter") )
	{
	if(  ob->query("party") && ob->query("party/party_name") != HIG "����" NOR )
	{
		message_vision("$Nҡҡͷ����$n˵�������Ѿ�������������ˣ����������������̡�\n",me,ob);
		return 1;
	}
//	if (ob->query("weiwang")>49)
//	{
//		message_vision("����ʹ��$Nҡҡͷ��˵����$N�Ѿ�������ػ��ˣ��������������̡�\n",ob);
//		return 1;
//	}
//	if(ob->query("shenlongjiao")) 
//	{
//		command("shake "+ob->query("id") );
//		message_vision("����ʹ��$Nҡҡͷ��˵����$N�Ѿ����������ˣ��������������̡�\n",ob);
//		return 1;
//	}
   	if( !mapp(party = ob->query("party")) && present("tuijian xin1", ob ))
   	{
		if ( (string)ob->query("gender") == "Ů��" ) men="��";
		else if ( (string)ob->query("class")=="taoist" 
		  || (string)ob->query("class")=="bonze" ) men="��";
		else if ( ob->query("shen") < 0 ) men="��";
		else men="��";

		ob->delete_temp("have_letter");

		if ( (string)ob->query("gender") == "Ů��" )
			command("say �������ֵ�һŮ�к��ܣ����ǿ�ϲ�ɺ� !");
		else 
			command("say �������ֵ�һӢ�ۺú������ǿ�ϲ�ɺ� !");

		party = allocate_mapping(5);
		party["party_name"] = HIG "����" NOR;
		party["rank"] = men+"���Ž���";
		party["level"] = 1;
		party["tasks"] = 0;
		party["enter_time"] = time();
		ob->set("party", party);

		command("smile");
		message_vision("����ʹ��$N˵������ϲ$N��Ϊ����"+men+"���Ž��ڣ�\n",ob);
		remove_call_out("destroying");
		call_out("destroying", 1, me, obj);
		return 1;
	}
   	if( party["party_name"] != HIG "����" NOR )
	{
		message_vision("����ʹ��$Nҡҡͷ��˵����$N�Ѿ�������������ˣ��������������̡�\n",me,ob);
		return 1;
	}
	else
		message_vision("$Nҡҡͷ����$n˵�������Ѿ��������̵����ˡ�\n",me,ob);
	}
        command("?");
        command("say �ⶫ�����ҿ�û��ʲ���á�");
	return 0;

}

void destroying(object me, object obj)
{
	destruct(obj);
	return;
}
