//Created by RoomEditer on 01-8-21.
inherit ROOM;

void create()
{
	set("short","练武场");
	set("long",@LONG
这就是不平社的东练武场了。平时不平弟子都是在这里苦练武功的。
LONG
	);
	set("exits",([

		"south" : __DIR__"guodao1",
	]));
	set("objects",([
		"/d/shaolin/npc/mu-ren" : 5,
	]));
	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}
