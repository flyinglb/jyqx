// Room: /d/fuzhou/ximendajie.c
// Date: May 12, 98  Java

inherit ROOM;

void create()
{
	set("short", "���Ŵ��");
	set("long", @LONG
��ʯ��·��ֱ����չ��ȥ��ֱͨ���š��ֱ���ȥ��һƬ
������ˮɫ������ȴ��һƬ���֣�������ʣ���Զ������
LONG );
	set("exits", ([
                "west"  : __DIR__"ximen",
                "east"  : __DIR__"xidajie",
                "north" : __DIR__"xihu",
                "south" : __DIR__"xichansi",
	]));
	set("objects", ([
                __DIR__"npc/cui": 1,
	]));
	set("outdoors", "quanzhou");
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

