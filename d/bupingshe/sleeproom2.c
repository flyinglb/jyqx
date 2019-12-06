//Created by RoomEditer on 01-8-21.
inherit ROOM;

void create()
{
	set("short","休息室");
	set("long",@LONG
一间幽静的休息室。只见几个大汉正在蒙头大睡。
LONG
	);
	set("exits",([

		"north" : __DIR__"guodao2",
	]));
	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}
