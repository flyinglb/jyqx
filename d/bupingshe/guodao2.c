//Created by RoomEditer on 01-8-21.
inherit ROOM;

void create()
{
	set("short","����");
	set("long",@LONG
����һ��ƽ̹��ʯ��·�������ǲ�ƽ��������䳡������Ϊһ��Ϣ�ң�������ǲ�ƽ������Ĺ㳡��
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
