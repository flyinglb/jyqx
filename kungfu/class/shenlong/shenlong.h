// shenlong.h for join shenlongjiao
#include <ansi.h>;

int do_join(string arg)
{
        object me, ob;
	string men;
	mapping party;

	me = this_object () ;
	ob = this_player () ;

	if( !arg || arg!="shenlongjiao" )
		return notify_fail("��Ҫ����ʲô��֯��\n"); 

	if ((int)ob->query("shen") > 0)
	{
	message_vision(HIR"$N��$n��ŭ����������̣�һ����Ͳ��Ǻ���! \n"NOR,me,ob);
		set_leader(this_player());
		remove_call_out("kill_ob");
		me->kill_ob(ob); 
		return 1;
	}

//	if( !mapp(party = ob->query("party")) || party["party_name"] != HIY "������" NOR )
	if(  ob->query("party") && ob->query("party/party_name") != HIY "������" NOR )
	{
		message_vision("$Nҡҡͷ����$n˵�������Ѿ�������������ˣ����������������̡�\n",me,ob);
		return 1;
	}
	if( ob->query("party/party_name") == HIY "������" NOR )
	{
		message_vision("$Nҡҡͷ����$n˵�������Ѿ����������̵����ˡ�\n",me,ob);
		return 1;
	}
	if ( (string)ob->query("gender") == "Ů��" ) men=HIR"��";
	else
	{
		switch (random(4))
		{
		case 0 : men=HIG"��"; break;
		case 1 : men=HIW"��"; break;
		case 2 : men=BLU"��"; break;
		default: men=YEL"��"; break;
		}
	}
	party = allocate_mapping(5);
	party["party_name"] = HIY "������" NOR;
	party["rank"] = men+"��ʹ"NOR"���½���";
	party["level"] = 1;
	party["tasks"] = 0;
	party["enter_time"] = time();
	ob->set("party", party);

	command("smile");
	message_vision("$N��$n˵���������ʱ��"+men+"��ʹ"NOR+"����Ч���ɣ�\n", me, ob);
	return 1;
}

