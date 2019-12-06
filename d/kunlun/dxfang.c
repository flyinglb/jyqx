//Robin 2000.5.15

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","东厢房");
	set("long", @LONG
这里是朱家仆人居住的房间，两排十多张板床占据了这房间的大多数空间，
床上都是些粗布用品，但却整齐干净。门边摞了几只黄泥烧制的脸盆。
LONG );
	set("exits", ([
		"west"  : __DIR__"beiyuan",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

