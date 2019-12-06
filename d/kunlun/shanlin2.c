//Robin 2000.5.15

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","山林");
	set("long", @LONG
依旧是以杉为主的树林，但脚下的路却是崎岖不平的。人在林中，路在树
间，树很高，挂满了冰雪，遮得住阳光。远远看得见小村和山峰，而前方又可
以看到白雪皑皑的山峦。
LONG );
	set("exits", ([
		"southup"   : __DIR__"shanlin1",
		"northwest" : __DIR__"baixiang",
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	setup();
	replace_program(ROOM);
}

