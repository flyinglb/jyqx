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
		return notify_fail("你要加入什么组织？\n"); 

	if(  ob->query("party") && ob->query("party/party_name") != HIW "日月神教" NOR )
	{
		message_vision("$N摇摇头，对$n说道：你已经加入其他帮会了，不能再入我日月神教。\n",me,ob);
		return 1;
	}
	if( ob->query("party/party_name") == HIW "日月神教" NOR )
	{
		message_vision("$N摇摇头，对$n说道：你已经是我日月神教的人了。\n",me,ob);
		return 1;
	}
	if ( (string)ob->query("gender") == "女性" ) men=HIM"天香";
	else
	{
		switch (random(3))
		{
		case 0 : men=HIC"青龙"; break;
		case 1 : men=WHT"白虎"; break;
		default: men=HIY"风雷"; break;
		}
	}
	party = allocate_mapping(4);
	party["party_name"] = HIW "日月神教" NOR;
	party["rank"] = men+"堂"NOR"教众";
	party["level"] = 1;
	party["tasks"] = 0;
	party["enter_time"] = time();
	ob->set("party", party);

	command("smile");
	message_vision("$N对$n说道：你就暂时在"+men+"堂"NOR+"效力吧！\n", me, ob);
	return 1;
}

