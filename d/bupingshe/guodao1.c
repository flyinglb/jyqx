//Created by RoomEditer on 01-8-21.
inherit ROOM;

void create()
{
	set("short","过道");
	set("long",@LONG
这是一条平坦的石板路，北面是不平社的东练武场，南面是一间休息室，往西就是不平社的中心广场了。
LONG
	);
	set("exits",([

		"west" : __DIR__"guangchang",
		"south" : __DIR__"sleeproom1",
		"north" : __DIR__"wuchang1",
	]));
	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}
