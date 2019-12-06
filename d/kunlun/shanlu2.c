//Robin 2000.5.9

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","昆仑山路");
	set("long", @LONG
终于到了真正被称为是昆仑山的山下，南瞻苍天浩浩，白云悠悠；北瞰了
无生气，黄沙漫漫；东望沃野千里，晴天辽阔；西眺高山巍巍，迤逦万里。
LONG );
	set("exits", ([
//              "eastdown" : __DIR__"shilu3",
		"south" : __DIR__"shanlu1",
		"east" :  __FILE__,
		"west" :  __FILE__,
		"north" : __FILE__,
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	setup();
	replace_program(ROOM);
}

