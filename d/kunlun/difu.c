#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","�ظ�");
	set("long", @LONG
һƬ�ڰ�����أ�������������Щʲô����Լ���ƺ���Щ��Ӱ���ƶ�����
���ڶ��е�����ȴ��ɭ���µý��������в���Ϊ֮�󶯣�������ĵ���������
ô����������һ����ӰƮ������ǰ��������ϸ����Ҳֻ�������Ӱ�ӵ�������
������һ�ѽ������뵽�������Ŀȴ�ǲ����ܡ�
LONG );
	set("exits", ([
		"east"	:  __FILE__,
		"west"	:  __FILE__,
		"north" :  __FILE__,
		"south" :  __FILE__,
	]));
	set("objects", ([
		__DIR__"npc/hezudao" :1,
	]));
	setup();
}
int valid_leave(object me, string dir)
{
	if ( dir == "south")
		me->add_temp("mark/steps",1);
	if ( dir == "north")
		me->add_temp("mark/steps",-1);
	if (me->query_temp("mark/steps") == 10)
	{
		me->move("/d/death/road1");
		me->delete_temp("mark/steps");
		return notify_fail("�㰵������һ�Ѻ�����ǰ�ľ��������б仯�ˡ�\n");
	}  
	if (me->query_temp("mark/steps") == -10)
	{  
		me->move("/d/death/road1");
		me->delete_temp("mark/steps");
		return notify_fail("�㰵������һ�Ѻ�����ǰ�ľ��������б仯�ˡ�\n");
	}
	return ::valid_leave(me,dir);
}
