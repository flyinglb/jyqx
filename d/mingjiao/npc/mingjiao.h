// MingJiao.h for all npc of mingjiao

void greeting(object me, object ob)
{
	if ( environment(ob) != environment(me) ) return;
	if ( ob->query("party/party_name") == HIG "����" NOR )
	{
//	if ( ob->query("party")["level"] < me->query("level"))
		message_vision("$N��$n��������˵����"+me->query("title")+me->query("name")
			+"���μ�"+ob->query("party")["rank"]+ob->query("name")+"��\n", me, ob );
	}

}
