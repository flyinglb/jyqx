//Created by RoomEditer on 01-8-21.
inherit ROOM;

void create()
{
	set("short","���䳡");
	set("long",@LONG
����ǲ�ƽ��Ķ����䳡�ˡ�ƽʱ��ƽ���Ӷ�������������书�ġ�
LONG
	);
	set("exits",([

		"south" : __DIR__"guodao1",
	]));
	set("objects",([
		"/d/shaolin/npc/mu-ren" : 5,
	]));
	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}
