//Created by RoomEditer on 01-8-21.
inherit ROOM;

void create()
{
	set("short","议事厅");
	set("long",@LONG
这是一个宽敞的大厅，里面整齐的摆着许多桌椅，平时不平社的大事都是在这里有帮主和长老们商议处理的。
LONG
	);
	set("exits",([
                "east" : __DIR__"guodao3",
	]));
	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}
