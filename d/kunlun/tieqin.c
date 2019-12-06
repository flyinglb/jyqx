//Robin 2000.5.9

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","铁琴居");
	set("long", @LONG
这里就是昆仑派掌门人“铁琴先生”何太冲居所的正房，房内正中的方桌
上摆着一张琴，据说昆仑始祖“昆仑三圣”何足道当年在少林寺外为郭襄演奏
用的就是这张琴。
LONG );
	set("exits", ([
		"south" :  __DIR__"shijian",
		"north" :  __DIR__"zoulang1",
	]));
	set("objects", ([
		__DIR__"npc/hetaichong" : 1,
	]));
	setup();
	replace_program(ROOM);
}

