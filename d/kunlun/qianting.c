//Robin 2000.5.10

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","前厅");
	set("long", @LONG
这是这座庄子的前厅，厅内的摆设装饰均是南方风格。厅的正中悬了一幅
茶花图。图前一张方桌上摆了一把剑。桌旁的太师椅上坐着一个中年人。
LONG );
	set("exits", ([
		"north" : __DIR__"nanyuan",
		"south" : __DIR__"houyuan",
	]));
	set("objects", ([
		__DIR__"npc/wulie" : 1,
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

