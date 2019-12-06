//Robin 2000.5.15

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","内院");
	set("long", @LONG
一个不是很大的院子，院子周围有几座房舍，西面有一个花园。院子里种
植了松柏梧桐，有几盆花放置在正面的房屋前。
LONG );
	set("exits", ([
		"east"  : __DIR__"yashi",
		"south" : __DIR__"zhengfang1",
		"north" : __DIR__"neizhai",
		"northwest" : __DIR__"hhyuan",
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	setup();
	replace_program(ROOM);
}

