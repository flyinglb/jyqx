//Created by RoomEditer on 01-8-21.
inherit ROOM;

void create()
{
	set("short","����");
	set("long",@LONG
һ�����ź��̺��ʯ��·�������ǲ�ƽ����ʷ�������Ϊ��ƽ�������ͥ��������ǲ�ƽ��������Է��ˡ����Ͼ��ǲ�ƽ�㳡�ˡ�
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
