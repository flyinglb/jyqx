// art.c �����黭
// cck 3/7/97
//cool 10/10/98

inherit SKILL;
int do_play(string arg);

//void create() { seteuid(getuid()); }

int valid_enable(string usage)
{
        return (usage == "parry");
}


int valid_learn(object me)
{
	if ( me->query("int") < 24 && me->query_int() < 32)
	return notify_fail("�����黭���Ǽ������֮�£�" +RANK_D->query_respect(me)+"�ƺ�̫����������Щ��\n");

	if( (int)me->query("shen") < -10000 )
	return notify_fail("��ɱ�����飬����������ƽϢ����ͷħ������ֻ�����˼�������壿\n");

	if(me->query("family/master_name") != "�����" )
	return notify_fail("��һ������Ĵ��ˣ�ѧ��Щ�ḯ���˵Ķ�����ʲô��\n");

	return 1;
}

int practice_skill(object me)
{
	return notify_fail("�����黭ֻ�ܿ�ѧ(learn)����ߡ�\n");
}

void init()
{
		add_action("do_play", "play");
}

int do_play(string arg)
{
		object me = this_player();

		if ( !arg && (arg != "music") && (arg != "zheng") && (arg != "gu zheng")
			  && (arg != "wei qi") && (arg != "qi") && (arg != "go") )
			return notify_fail("��Ҫ��ʲô��\n");

		if ( present("gu zheng", this_player()) &&
			((arg == "music") || (arg == "zheng") || (arg == "gu zheng"))  )
		{
			if ( me->query_skill("art", 1) < 30 )
			{
				message_vision("$N�ڳ�һ�Ź��ݣ����������˼�����ֻ���������������£��������Ǻš�\n", me);
				me->receive_damage("jing", random(20) );
				me->receive_damage("qi", random(20) );
				return 1;
			}
	if ( me->query_skill("art", 1) >100 )
			{
				message_vision("$N�ڳ�һ�Ź��ݣ����������˼�����ֻ��������ƽ�ͣ��������������м��⡣\n", me);
				return 1;
			}
			me->receive_damage("jing", 10);
			me->receive_damage("qi", 10);
			me->improve_skill("art", (int)me->query_int()/4 + (int)me->query_skill("art", 1)/10);
		tell_object(me, "��ڳ�һ�Ź��ݣ����˵��ң�������������ֻ������������������������ࡣ\n");

			message_vision("ֻ��" + me->query("name") +
		  "���˴󷢣�����������������ֻ����ʱ�����������Įƽɳ������������\n"
		  "ʱ��С����ˮ�������˼ҡ�������������������������ʱ��������ࡣ\n",
			environment(me), ({me}) );

			return 1;
		}

		if ( present("wei qi", this_player()) && ((arg == "wei qi") || (arg == "qi") || (arg == "go")) )
		{
			if ( (me->query_skill("art", 1) < 40) )
			{
				message_vision("$N�ڳ�һ�����̣����о�Χ�壬ȴ�ܾ����ķ����ң�������������\n", me);
		        me->receive_damage("jing", random(20) );
				me->receive_damage("qi", random(20) );
				return 1;
			}
	if ( me->query_skill("art", 1) >100 )
			{
				message_vision("$N�ڳ�һ�����̣�ֻ�����沼�־��ڳ��ֻ֮�У����ܿ��С�\n", me);
				return 1;
			}

			me->receive_damage("jing", 10);
			me->receive_damage("qi", 10);
			me->improve_skill("art", (int)me->query_int()/4 + (int)me->query_skill("art", 1)/10);
			tell_object(me, "��ڳ�һ�����̣��о���Χ������ֻ������ƽ���ͣ��ܿ�ͷ·��붨�ˡ�\n");

			message_vision("ֻ��" + me->query("name") +
		  "���˴󷢣��������������������·��Ų��ʣ�һ��Ī������ģ����\n",
			environment(me), ({me}) );

		}
			return 1;
		}

string perform_action_file(string action)
{
    return __DIR__"art/" + action;
}

