//Robin 2000.5.10

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","祠堂");
	set("long", @LONG
祠堂的香案上供奉着数十个灵位，昏暗的光线下也看不清灵牌上的字。堂
中的幔帏、香案、蒲团、香炉上都落了一层灰尘，看来很久没有人来打扫也没
有人来祭拜了。只有香案下的一面木板(ban)倒是清洁得多，应该是最近有人
动过的。
LONG );
	set("exits", ([
		"south" : __DIR__"mudi",
	]));
	set("no_clean_up", 0);
	setup();
}
void init()
{
	add_action("do_move","move");
}
int do_move(string arg)
{
	if(arg == "ban")
	{
		message_vision ("$N移开地面上的木板，香案下出现一个洞。\n", this_player());
		set("exits/down", __DIR__"dong1");
		remove_call_out("close");
		call_out("close", 5, this_object());
		return 1;
	}
}
void close(object room)
{
	message("vision","只听“啪”的一声，移在一边的木板自行倒了下来，将地洞盖上了。\n", room);
	room->delete("exits/down");
}       
