//Robin 2000.5.9

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","客房");
	set("long", @LONG
这个客房里可以住的客人不是掌门人的客人，一般是门内弟子家里人来探
视时住的，不过这地方地处偏僻，就是门人的家人也很少有来的。于是这里就
常常成为男女弟子门偷情的好地方。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"south" : __DIR__"xiaoyuan2",
	]));
	set("sleep_room", "1");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
