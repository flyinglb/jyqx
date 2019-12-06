//Created by RoomEditer on 01-8-21.
inherit ROOM;

void create()
{
	set("short","不平社中心广场");
	set("long",@LONG
这是一个宽广的广场，四周是一座座宏伟的建筑。
LONG
	);
	set("exits",([
		"east" : __DIR__"guodao1",
		"west" : __DIR__"guodao2",
		"south" : __DIR__"damen",
		"north" : __DIR__"guodao3",
	]));
	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}
