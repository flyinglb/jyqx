#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","地府");
	set("long", @LONG
一片黑暗的天地，看不清这里有些什么，隐约间似乎有些黑影在移动，但
听在耳中的声音却阴森可怕得紧，你心中不由为之大动：“我真的到了阴间了
么？”缓缓地一个身影飘到了眼前，你想仔细看，也只发现这个影子的手中似
乎拿了一把剑，但想到看清楚面目却是不可能。
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
		return notify_fail("你暗自捏了一把汗，眼前的景象终于有变化了。\n");
	}  
	if (me->query_temp("mark/steps") == -10)
	{  
		me->move("/d/death/road1");
		me->delete_temp("mark/steps");
		return notify_fail("你暗自捏了一把汗，眼前的景象终于有变化了。\n");
	}
	return ::valid_leave(me,dir);
}
