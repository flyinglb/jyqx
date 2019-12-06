//Created by RoomEditer on 01-8-21.
inherit ROOM;

void create()
{
	set("short","过道");
	set("long",@LONG
一条铺着红地毯的石板路。东面是不平社的帐房，西面为不平社的议事庭，北面就是不平社帮主的卧房了。望南就是不平广场了。
LONG
	);
	set("exits",([
		"east" : __DIR__"zhangfang",
		"west" : __DIR__"yishiting",
		"south" : __DIR__"guangchang",
		"north" : __DIR__"wofang",
	]));
	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}
