//Robin 2000.5.9

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","昆仑山下");
	set("long", @LONG
终于到了真正被称为是昆仑山的山下，南瞻苍天浩浩，白云悠悠；北瞰了
无生气，黄沙漫漫；东望沃野千里，晴天辽阔；西眺高山巍巍，迤逦万里。
LONG );
	set("exits", ([
		"westup"  : __DIR__"shanlu4",
		"eastdown" : "/d/mingjiao/shanjiao",
		"north" : __DIR__"shanlu2",
		"south" : __DIR__"shanlu3",
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	setup();
	replace_program(ROOM);
}

