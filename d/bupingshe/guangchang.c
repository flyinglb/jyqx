//Created by RoomEditer on 01-8-21.
inherit ROOM;

void create()
{
	set("short","��ƽ�����Ĺ㳡");
	set("long",@LONG
����һ�����Ĺ㳡��������һ������ΰ�Ľ�����
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
