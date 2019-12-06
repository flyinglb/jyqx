//Created by RoomEditer on 01-8-21.
inherit ROOM;

void create()
{
	set("short","过道");
	set("long",@LONG
这是一条平坦的石板路。北面是不平社的南练武场，南面为一休息室，东面就是不平社的中心广场。
LONG
	);
	set("exits",([
		"east" : __DIR__"guangchang",
		"south" : __DIR__"sleeproom2",
		"north" : __DIR__"wuchang2",
	]));
	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}
