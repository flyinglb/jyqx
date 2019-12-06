//Created by RoomEditer on 01-8-21.
inherit ROOM;

void create()
{
	set("short","帐房");
	set("long",@LONG
这就是不平社帐房了，靠墙摆着几个书架，上面堆满了帐册!相传帐房先生方龙香是个很能算计的人。
LONG
	);
	set("exits",([

		"west" : __DIR__"guodao3",
	]));
	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}
