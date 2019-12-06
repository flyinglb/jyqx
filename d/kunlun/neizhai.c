//Robin 2000.5.15

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","内宅");
	set("long", @LONG
这是一间精雅别致的房间，房内家具摆设并不奢华，但却显示出主人高贵
的身份来。桌上一面古色古香的铜镜更加衬托出那种只有出身高贵的人才能拥
有这样的环境。
LONG );
	set("exits", ([
		"south" : __DIR__"neiyuan1",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

