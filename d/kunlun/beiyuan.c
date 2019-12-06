//Robin 2000.5.10

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","北大院");
	set("long", @LONG
这是北庄朱家的的前院，院里两条大狼狗紧紧注视着来往的每一个人，似
乎要把人吃掉。院子里种了几株白杨，树边停着一架独轮人力车。院子北边有
一座敞亮的房子。东西两边也各有一排厢房。房舍院落尽是南方风格，与这西
北地方很不协调。
LONG );
	set("exits", ([
		"east"  : __DIR__"dxfang",
		"west"  : __DIR__"xxfang",
		"north" : __DIR__"zhengfang1",
		"south" : __DIR__"zhuwu",
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	setup();
	replace_program(ROOM);
}

