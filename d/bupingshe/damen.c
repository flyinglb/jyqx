//Created by RoomEditer on 01-8-21.
inherit ROOM;

void create()
{
	set("short","不平社大门");
	set("long",@LONG
一座高大的石门，一面写着“不平社”的大匾高挂在上。望北就是不平社的广场了。
LONG
	);
	set("exits",([

		"north" : __DIR__"guangchang",
                "south"  : "/d/henshan/hsroad4",
	]));
	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}
