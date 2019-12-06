// ZhangQiShi.h for fight and get letter from ZhangQiShi

void init()
{
	object me,ob;
	me = this_object () ;
	ob = this_player () ;

	::init();

	add_action("do_join","join");

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

int accept_object(object ob, object obj)
{
	object me = this_object();

	mapping ob_party  = ob->query("party");

	if ( ob->query_temp("have_letter") && present("tuijian xin3", ob) ) 
	{
		command("say �������������ҵ��Ƽ���ȥ���������� ?");
		return 0;
	}

	if((obj->query("id") == "tieyan ling")
    && ob_party["party_name"] == "����"
	&& ob_party["level"] == 2
	&& !ob->query_temp("have_letter") ) 
	{
		ob->set_temp("fight_ok",1);
		command("say �ã���Ȼ�ѵõ�������ɣ����Ǿ�����֤һ���书��");
		remove_call_out("destroying");
		call_out("destroying", 1, me, obj);
		return 1;
	}

	if (obj->query("id") == "tuijian xin2" 
	&& ob->query_temp("have_letter") )
	{
		ob->set_temp("apprentice_ok",1);
	        command("say �ã�" + ob->query("name") + "����Ը�����������");
		remove_call_out("destroying");
		call_out("destroying", 1, me, obj);
		return 1;
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

int accept_fight(object ob)
{
	object me  = this_object();
	
	if ( !ob->query_temp("fight_ok") ) return 0;

	remove_call_out("checking");
	call_out("checking", 1, me, ob);

	ob->delete_temp("fight_ok");
	
	return 1;
}

int checking(object me, object ob)
{

	object obj;
	int my_max_qi, his_max_qi;

	my_max_qi  = me->query("max_qi");
	his_max_qi = ob->query("max_qi");

	if (me->is_fighting()) 
	{
		call_out("checking",2, me, ob);
                return 1;
	}

	if ( !present(ob, environment()) ) return 1; 

	if (( (int)me->query("qi")*100 / my_max_qi) <= 50 ) 
	{
                command("say ������ʤ����������������̵ļѵ��� ! ��ϲ���� !\n");
		message_vision("$N����$nһ���Ƽ��š�\n", me, ob);
		ob->set_temp("have_letter",1);
                obj=new("/d/mingjiao/obj/tuijianxin-3");
		obj->move(ob);
		return 1;
	}

	if (( (int)ob->query("qi")*100 / his_max_qi) < 50 ) 
	{
		command("say ����" + RANK_D->query_respect(ob) + 
                        "���ö����ϰ�������������������г���ͷ�� !\n");
		return 1;
	}

	return 1;  
}

void do_join()
{
	object me,ob;
	mapping ob_party;
	string qi,new_rank;

	me=this_object();
	ob=this_player();

        if (!(ob_party=ob->query("party"))||ob_party["party_name"]!="����")
	{
                command("say " + RANK_D->query_respect(ob) + "�뱾��������������֪�˾��Ǻ����⣿");
		return;
	}

	if ( ob_party["level"] <= me->query("level") )
	{
                command("say " + RANK_D->query_respect(ob) + "����������ҵ� !");
		return;
	}

	if ( ob_party["level"] == 1 )
	{
		if ( ob->query_temp("apprentice_ok") )
		{
			ob->delete_temp("have_letter");
			ob->delete_temp("apprentice_ok");
	
			command("say ������ !");
                        command("say �����ֵ�һ����֮�ţ����ǿ�ϲ�ɺ� !");

			qi = me->query("title")[11..30];

	        	command("say ��ϲ������Ϊ����"+qi+"���ڣ�");
			new_rank = qi + "����";
                        ob->set(ob_party["rank"],new_rank);
		}
		else
		{
			command("say " + RANK_D->query_respect(ob) + "����û���Ƽ��ţ�����Խ����ʦ��");
			return;
		}
	}

	return;
}

#include "mingjiao.h"
