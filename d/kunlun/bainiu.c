//Robin 2000.5.9

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","白牛山");
	set("long", @LONG
这里山势平缓，与远望的崇山峻岭风格迥异，山坡上长的不是高大的松与
杉，而是一种高仅及腰的黄而近白的野草，间或有些叫不上名的白色小花。从
这里向西面看去，可见十数间青砖瓦房，其上尚见炊烟缈缈，看得最清楚的是
山脚下一个练武场模样的空旷地。北边两山之间的山坡上有一片农田。
LONG );
	set("exits", ([
		"northdown"  : __DIR__"shantian1",
		"southdown"  : __DIR__"shanlu6",
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	setup();
	replace_program(ROOM);
}
