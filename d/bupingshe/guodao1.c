//Created by RoomEditer on 01-8-21.
inherit ROOM;

void create()
{
	set("short","����");
	set("long",@LONG
����һ��ƽ̹��ʯ��·�������ǲ�ƽ��Ķ����䳡��������һ����Ϣ�ң��������ǲ�ƽ������Ĺ㳡�ˡ�
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
