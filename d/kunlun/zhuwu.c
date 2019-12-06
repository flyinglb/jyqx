//Robin 2000.5.10

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","朱武连环庄");
	set("long", @LONG
一直走到跟前你才发现，远远看见的村庄其实是两座村庄，而这两座村子
相距实在太近了，以至到了跟前你也需要仔细才看得明白。两座村庄几乎紧紧
贴在一起，只有脚下这条继续西向的路才把这两座村庄划分开来。两座庄子的
庄门都在靠路侧的东头，前面两个身着仆童服饰的少年正倚着庄门聊天，一面
用好奇的眼光望着远来的你。
LONG );
	set("exits", ([
		"east"  : __DIR__"jilu3",
//		"west"  : __DIR__"jilu4",
		"north" : __DIR__"beiyuan",
		"south" : __DIR__"nanyuan",
	]));
	set("objects", ([
		__DIR__"npc/jiading" : 2,
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	setup();
	replace_program(ROOM);
}

