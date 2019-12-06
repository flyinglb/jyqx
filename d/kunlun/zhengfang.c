//Robin 2000.5.9

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","正房");
	set("long", @LONG
这里是何太冲和夫人班淑娴的卧室，房中也摆放了不少鲜花，但明显和后
花园中的鲜花风格不同。这里大都是中原可以见到的牡丹、菊花、芍药、水仙
之类。掌门夫人站在窗前，望着园中的奇特鲜花发呆。
LONG );
	set("exits", ([
		"south" :  __DIR__"houhuayuan",
	]));
	set("objects", ([
		__DIR__"npc/binv" : 2,
		__DIR__"npc/banshuxian" :1,
	]));
	setup();
	replace_program(ROOM);
}
