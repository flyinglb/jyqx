//Robin 2000.5.9

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","小院");
	set("long", @LONG
这里是昆仑派弟子居住的房舍间的另外一个空旷地，所谓院子其实并没有
围墙，一是这里很少有外人来，二是四处尽是高山，也很难有人可以通过那里
到这儿的。这“院子”从南面向下是另一个相似的“院子”。
LONG );
	set("exits", ([
		"southdown" :  __DIR__"xiaoyuan1",
		"north" : __DIR__"kefang",
		"west" : __DIR__"sleeproom",
		"east" : __DIR__"playroom",
	]));
	set("objects", ([
		__DIR__"npc/dizi" : 3,
		__DIR__"npc/suxi" :1,
	]));
	set("outdoors", "kunlun");
	setup();
	replace_program(ROOM);
}

