//Created by RoomEditer on 01-8-21.
inherit ROOM;

void create()
{
	set("short","帮主卧室");
	set("long",@LONG
一间舒适的卧房，里面摆着一些昂贵的家具。相传不平社的帮主行天虽然奢侈，但相当民主。
LONG
	);
	set("exits",([

		"south" : __DIR__"guodao3",
	]));
	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}
