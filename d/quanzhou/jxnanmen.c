// Room: /d/quanzhou/jxnanmen.c
// Date: May 21, 96   Jay

inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
�����Ǽ��˵����š���Χ����ï�ܵ����֡������������
���Ͽ��븣�������Ͼ��Ǻų����õĺ��ݳ��ˡ�
LONG );
	set("exits", ([
                "north" : __DIR__"jiaxing",
                "east" : __DIR__"tieqiang",
		"south" : __DIR__"qzroad4",
		"southeast": "/d/hangzhou/road1",
	]));
	set("no_clean_up", 0);
	set("outdoors", "quanzhou");
	setup();
	replace_program(ROOM);
}

