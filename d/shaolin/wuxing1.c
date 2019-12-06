// Room: /d/shaolin/wuxing1.c
// Date: YZC 96/02/06

#include <ansi.h>

inherit ROOM;

string* dirs = ({"east", "south", "west", "north"});

void create()
{
	set("short", HIG "���ж�" NOR);
	set("long", HIG @LONG
�������ж������������ԱȽϸ���Щ���ı��ɿ���ľ��
����ʵʵ�ĵط���������ߵ��ȥ�������Ƶ�����������������ʵ
�ĵľ����м��ߺ�û�и�������������������ǡ������㻹��
��������һ�ԣ�ϣ���ܴ������ȱ�ڡ�
LONG
NOR	);
	set("exits", ([
		"east" : __DIR__"wuxing0",
		"south" : __DIR__"wuxing3",
		"west" : __DIR__"wuxing4",
		"north" : __DIR__"wuxing2",
	]));
	set("no_clean_up", 0);
	setup();
}

int check_out(object me)
{
	int metal, wood, water, fire, earth;

	metal = me->query_temp("wuxing/��");
	wood = me->query_temp("wuxing/ľ");
	water = me->query_temp("wuxing/ˮ");
	fire = me->query_temp("wuxing/��");
	earth = me->query_temp("wuxing/��");

	if ( metal > 0 &&
		metal == wood && metal == water &&
		metal == fire && metal == earth )
	{
		me->delete_temp("wuxing");
		me->move(__DIR__"andao2");
		return (1);
	}
	return (0);
}

int valid_leave(object me, string dir)
{
	int count;

	if (member_array(dir, dirs) != -1)
	{
		if (dir == "south")
		{
//			write("*ľ����*\n");
			count = me->query_temp("wuxing/��");
			count++;
			me->set_temp("wuxing/��", count);
			if (check_out(me))
				return notify_fail("��˳�����߳��������Թ���\n");
		}
		else if (dir == "west")
		{
//			write("*ľ����*\n");
			me->delete_temp("wuxing");
			me->move(__DIR__"jianyu1");
			return notify_fail("��������أ�����ɮ�ࡣ\n");
		}
	}
	return ::valid_leave(me, dir);
}

