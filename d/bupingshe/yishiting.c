//Created by RoomEditer on 01-8-21.
inherit ROOM;

void create()
{
	set("short","������");
	set("long",@LONG
����һ�����Ĵ�������������İ���������Σ�ƽʱ��ƽ��Ĵ��¶����������а����ͳ��������鴦��ġ�
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
