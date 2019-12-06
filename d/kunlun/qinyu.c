//Robin 2000.5.9

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","琴羽厅");
	set("long", @LONG
厅中的古琴已经被搬到铁琴居了，看来现在这位何掌门并不精于音律，不
然怎么只搬走了琴却不拿琴谱。现在厅里琴案上也落满了尘土，案角上放着一
本琴谱。
LONG );
	set("exits", ([
		"west"  : __DIR__"sanshengju",
	]));
	set("objects", ([
		__DIR__"obj/qinpu" : 1,
	]));
	setup();
	replace_program(ROOM);
}
