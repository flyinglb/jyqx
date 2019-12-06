//Robin 2000.5.9

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","娱乐室");
	set("long", @LONG
这里是昆仑派弟子私下里偷偷开辟出来的用来游戏的房间，因为掌门人很
少光顾弟子们的居所，所以弟子们也就乐得逍遥。不过这里也没什么可以玩的
东西，就是在屋角处放了几个铁盒子，里面传出蛐蛐的声音，应该是有蟋蟀在
里面，大概这就是他们平时的玩具了。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"west" : __DIR__"xiaoyuan2",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
