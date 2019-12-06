//Robin 2000.5.9

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","小院");
	set("long", @LONG
这里是昆仑派弟子居住的房舍间的一个空旷地，所谓院子其实并没有围墙，
一是这里很少有外人来，二是四处尽是高山，也很难有人可以通过那里到这儿
的。这“院子”从北面向上是另一个相似的“院子”。
LONG );
	set("exits", ([
		"east"  : __DIR__"qipan",
		"west" :  __DIR__"xiaochufang",
		"south" : __DIR__"fangshe",
		"northup" : __DIR__"xiaoyuan2",
	]));
	set("objects", ([
		__DIR__"npc/dizi" : 3,
		__DIR__"npc/zhanchun" :1,
	]));
	set("outdoors", "kunlun");
	setup();
	replace_program(ROOM);
}

