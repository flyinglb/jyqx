//Robin 2000.5.9

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","后花园");
	set("long", @LONG
这里是掌门人家内宅中后花园的一角，到处种满了奇异的花草，人已无法
在这花草丛中找到可以走的路。在这里能看到的除了花草之外，只有一面墙壁
和属于这墙壁上的一个窗户(window)，窗子的那边应该是五姑的卧房。
LONG );
	set("objects", ([
		__DIR__"obj/lingzhilan" : 1,
	]));
	set("no_clean_up", 0);
	set("outdoors","kunlun");
	setup();
}
void init()
{
	add_action("do_jump", "jump");
}
int do_jump(string arg)
{
	object me;
	me = this_player();
	if (!arg || arg != "window") 
	return 1;
	message_vision("$N从窗户跳了进去。\n", me);
	me->move(__DIR__"cefang");
	message_vision("$N从窗外跳了进来。\n", me);
	return 1;
}
