//Robin 2000

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","卧室");
	set("long", @LONG
这是昆仑弟子休息睡觉的地方，除了几张床外，只有几件粗木做的家具。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"east" : __DIR__"xiaoyuan2",
	]));
	set("sleep_room", 1);
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
