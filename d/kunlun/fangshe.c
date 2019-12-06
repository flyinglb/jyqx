//Robin 2000.5.9

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","房舍");
	set("long", @LONG
这房里住着两个变成白痴的人，据说他们两个当年在东海王盘山上曾经历
过一场惊天动地的惨案，但他们自己已经说不太明白了。
LONG );
	set("exits", ([
		"north" :  __DIR__"xiaoyuan1",
	]));
	set("objects", ([
		__DIR__"npc/jiangtao" : 1,
		__DIR__"npc/gaozecheng" : 1,
	]));
	setup();
	replace_program(ROOM);
}

