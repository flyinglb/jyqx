// /guanwai/damenkan.c

inherit ROOM;

void create()
{
	set("short", "���ſ���");
	set("long", @LONG
�������ؽ��򶫵Ĺŵ�����Ϊ��ɽ�ɲεĲο����ߣ����Ҳ�ơ���·��
��ǰ��һ��Сɽ�ض�ȥ·�����������ſ�����Ϊ��ȥ�ɲεĵ�һ�����ϣ���
����Ϊ���ſ��ӡ������ǿ������ɻ������ɻ����ڶ���ʱ�����ͨ�У�����
������ֻ���Ҵ��Ұ�æ�ˡ�
LONG );
	set("exits", ([
		"northeast"  : __DIR__"ermenkan",
		"west"       : __DIR__"bingmian",
	]));
	set("no_clean_up", 0);
	set("outdoors", "guanwai");
	setup();
//	replace_program(ROOM);
}
int valid_leave(object me, string dir)
{
	string chn_month;
	object obj, *ob;
        int i,j;

	if (dir=="west")
	{
		chn_month = CHINESE_D->chinese_month((time()-890000000)*60);
		if (chn_month=="ʮ��" || chn_month=="һ" || chn_month=="��" ||
		 chn_month=="��" || chn_month=="��" || chn_month=="��")
		{
			message_vision("$N������ᶳ����׳���Ӳȱ�������\n\n", me);
			if (random(me->query_dex())<20)
			{
				me->receive_wound("qi",20);
				me->receive_damage("qi",20);
			message_vision(chn_month+"$Nֻ���ý���һ����ȫ���ڿն��𣬽��ʵʵ��ˤ���˱����ϣ�\n", me);
			}
			return 1;
		}
		else
		{
			j = 0;
			ob = all_inventory(environment(me));
			for(i=0; i<sizeof(ob); i++)
			{
				if ( (!userp(ob[i])) && (ob[i]->query("id")=="chuan fu"))
					j = 1;
			}
			if (j == 0)
			{
				obj = new(__DIR__"npc/chuanfu1");
				obj -> move(environment(me));
			message_vision("�����߳�һ������վ�ڱ��ϵ����ۿ���$N��", me);
			}
			else
			message_vision("�������Ա����۵���$N����", me);
			return notify_fail("���滯�������ǳ˴��ɣ�\n");
		}
	}
	return 1;
}

