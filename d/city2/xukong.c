
inherit ROOM;

void create()
{
	set("short", "����ξ�");
	set("long", @LONG
�����������ͷ׵�����ξ������������Եõ�����Ҫ��һ�С�����
һ�С�����һ�С�����������������
LONG );
	set("exits", ([
		"south" : __DIR__"tingyu",
		"east" : __DIR__"jifang",
	]));
//	set("objects", ([ "/u/wind/wind.c" : 1 ]));
	set("no_clean_up", 0);
	setup();
}

