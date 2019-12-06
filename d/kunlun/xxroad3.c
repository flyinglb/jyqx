// Robin 2000.5.10

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","小路");
	set("long", @LONG
道路依旧在山里迤俪，路边的草木杂乱了很多，路也看不出是不是路了，
路上尽是丛生的杂草，其间没有多少平整的地方，很多细碎的石头散步在路和
两旁。再往北面是一个被称为“乱石坡”的山坡。
LONG );
	set("exits", ([
		"south" :  __DIR__"xxroad2",
		"north" :  __DIR__"luoshipo",
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	setup();
	replace_program(ROOM);
}

