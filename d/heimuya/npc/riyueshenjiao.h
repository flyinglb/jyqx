// riyueshenjiao.h for join riyueshenjiao
// by Robin
#include <ansi.h>;

int do_join(string arg)
{
//        object me, ob, obj ;
        object me, ob;
	string men;
	mapping party;

	me = this_object () ;
	ob = this_player () ;

	if( !arg || arg!="riyueshenjiao" )
		return notify_fail("��Ҫ����ʲô��֯��\n"); 

	if(  ob->query("party") && ob->query("party/party_name") != HIW "�������" NOR )
	{
		message_vision("$Nҡҡͷ����$n˵�������Ѿ�������������ˣ�����������������̡�\n",me,ob);
		return 1;
	}
	if( ob->query("party/party_name") == HIW "�������" NOR )
	{
		message_vision("$Nҡҡͷ����$n˵�������Ѿ�����������̵����ˡ�\n",me,ob);
		return 1;
	}
	if ( (string)ob->query("gender") == "Ů��" ) men=HIM"����";
	else
	{
		switch (random(3))
		{
		case 0 : men=HIC"����"; break;
		case 1 : men=WHT"�׻�"; break;
		default: men=HIY"����"; break;
		}
	}
	party = allocate_mapping(4);
	party["party_name"] = HIW "�������" NOR;
	party["rank"] = men+"��"NOR"����";
	party["level"] = 1;
	party["tasks"] = 0;
	party["enter_time"] = time();
	ob->set("party", party);

	command("smile");
	message_vision("$N��$n˵���������ʱ��"+men+"��"NOR+"Ч���ɣ�\n", me, ob);
	return 1;
}

