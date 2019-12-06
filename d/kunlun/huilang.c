//Robin 2000.5.15

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","回廊");
	set("long", @LONG
一个木栏青瓦的十字长廊，一些不知名的花草盘绕着已经漆色班驳的栏杆。
回廊的南边通向一个院子，那里是朱家小姐养狗的地方；北面是一个花园的一
角，面对回廊的是一座怪石假山；东面通向朱家的正房；西面是一片杂草丛生
的荒地。
LONG );
	set("exits", ([
		"east"  : __DIR__"zhengfang1",
		"north" : __DIR__"jiashan",
		"south" : __DIR__"laying",
	]));
	set("objects", ([
		__DIR__"npc/binv" : 1,
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

