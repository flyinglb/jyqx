//Created by RoomEditer on 01-8-21.
inherit ROOM;

void create()
{
	set("short","��ƽ�����");
	set("long",@LONG
һ���ߴ��ʯ�ţ�һ��д�š���ƽ�硱�Ĵ��Ҹ߹����ϡ��������ǲ�ƽ��Ĺ㳡�ˡ�
LONG
	);
	set("exits",([

		"north" : __DIR__"guangchang",
                "south"  : "/d/henshan/hsroad4",
	]));
	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}
