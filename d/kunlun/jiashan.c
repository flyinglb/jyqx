//Robin 2000.5.15

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","花园一角");
	set("long", @LONG
这是花园里地势最高的地方，可以远眺出庄子看到远远的青山白云。在这
小坡的最高点，坐落了一个很多古怪石头堆起的假山。在假山的一个角上，有
一块大石有点特别，不知道是不是可以移(move)得开。
LONG );
	set("exits", ([
		"northeast"  : __DIR__"hhyuan",
		"south" : __DIR__"huilang",
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	setup();
}
void init()
{
	add_action("do_move","move");
}
int do_move(string arg)
{
	if(arg == "jiashan")
	{
		message_vision ("$N用力推动假山，地上出现一个洞。\n", this_player());
		set("exits/down", __DIR__"dong8");
		remove_call_out("close");
		call_out("close", 5, this_object());
		return 1;
	}
}
void close(object room)
{
	message("vision","被推开的假山缓缓碾回原地，把洞口掩上了。\n", room);
	room->delete("exits/down");
}       

