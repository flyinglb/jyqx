//Robin 2000.5.9

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","兵器场");
	set("long", @LONG
这里是试剑厅东墙角，有一个兵器架，上面放着几把练习用的竹剑。
LONG );
	set("exits", ([
		"west" :  __DIR__"shijian",
	]));
	set("objects", ([
                "/clone/weapon/zhujian" : 4,
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

