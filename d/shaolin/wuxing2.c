// Room: /d/shaolin/wuxing2.c
// Date: YZC 96/02/06

#include <ansi.h>

inherit ROOM;

string* dirs = ({"east", "south", "west", "north"});

void create()
{
	set("short", HIB "���ж�" NOR);
	set("long", HIB @LONG
�������ж���һ�������������������ˮ��ŵ��Ǻ�
������࣬һ����ȥ�����ɵ�ɢ����������һ������ð��ˮ�档
��ɲ�����ˮ���ϲ�ʱƮ����һ���߽��÷��׵ĸ�ʬ����ֻ����
�������������£���ʬ��ҧ����ľȫ�ǡ��ı��ôֲڵ�Ƭ���ݶ�
���ɣ�һ�ſ�ˮ������ǽ�ڹ�����������ˮ�У�
LONG
NOR	);
	set("exits", ([
		"east" : __DIR__"wuxing1",
		"south" : __DIR__"wuxing4",
		"west" : __DIR__"wuxing0",
		"north" : __DIR__"wuxing3",
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
		if (dir == "east")
		{
//			write("*ˮ��ľ*\n");
			count = me->query_temp("wuxing/ľ");
			count++;
			me->set_temp("wuxing/ľ", count);
			if (check_out(me))
				return notify_fail("��˳�����߳��������Թ���\n");
		}
		else if (dir == "north")
		{
//			write("*ˮ�˻�*\n");
			me->delete_temp("wuxing");
			me->move(__DIR__"jianyu1");
			return notify_fail("��������أ�����ɮ�ࡣ\n");
		}
	}
	return ::valid_leave(me, dir);
}

