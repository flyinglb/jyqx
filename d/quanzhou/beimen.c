// Room: /d/quanzhou/beimen.c
// Date: May 7, 96   Jay

inherit ROOM;

void create()
{
	set("short", "Ȫ�ݱ���");
	set("long", @LONG
�������Ϸ���һ��Ȫ�ݵı��š��������򱱿ɵ���ԭ��
LONG );
	set("exits", ([
                "north" : "/d/fuzhou/puxian",
                "south" : __DIR__"zhongxin",
	]));
	set("outdoors", "quanzhou");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

