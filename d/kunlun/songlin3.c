//Robin 2000.5.10

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","雪岭云杉林");
	set("long", @LONG
在山林间的空隙间可以看到，四下尽是那种笔直若屏风的山峦，而且山山
相连，远处的又高过近处的。无尽的云杉充斥在这无尽的山里，让人无法去感
受什么是尽头。前面路旁一只受伤的小猴子正以一种奇异的眼光望着你，你觉
得有一种说不出来的感觉笼罩在心头。
LONG );
	set("exits", ([
		"southeast"  : __DIR__"songlin2",
		"southup"  : __DIR__"doupo",
		"west" :  __DIR__"cunlu1",
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	setup();
}
int valid_leave(object me, string dir)
{
	if (me->query_skill("dodge",1) < 40
	&& dir == "southup")
	{
		message_vision (
"$N往南面是山坡爬去，却一不小心失足摔了下来……\n",me);
		me->add("qi", -20);
		me->add("jing", -20);
		me->unconcious();
		return notify_fail();
	}
	return ::valid_leave(me, dir);
}
//做南上的路身法不足上不去，想去朱武庄的人需要：
//治疗受伤的猴子后会出现朱九真与恶狗，
//武功若差到不足30级会被狗咬晕，然后被带到朱武庄。

