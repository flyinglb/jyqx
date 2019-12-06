//Robin 2000.5.9

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","小厨房");
	set("long", @LONG
这个小厨房要比那个大厨房大了很多，可能是因为这里的食物要差一些的
缘故，昆仑弟子都在这里进食，并且没什么人伺候，都是自己动手，不过谁要
运气好，可能会有前一个人做多剩下的东西。
LONG );
	set("exits", ([
		"east" :  __DIR__"xiaoyuan1",
	]));
	set("objects", ([
		__DIR__"obj/shaobing" : 3,
		__DIR__"obj/wan" : 1,
	]));
	setup();
	replace_program(ROOM);
}

