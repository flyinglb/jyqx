// Room: /d/fuzhou/fzroad4.c
// Date: May 12, 98  Java

inherit ROOM;

void create()
{
	set("short", "���ӹŵ�");
	set("long", @LONG
����������������ɽ�������������Ĺ���̣����ղ�����⡣
ɽ�ж������޳�û�޳�����·������
LONG );
	set("exits", ([
		"southwest" : __DIR__"fzroad5",
		"northeast" : __DIR__"yanping",
	]));
        set("objects", ([
		__DIR__"npc/wubushe" : 1,
	]));
	set("outdoors", "quanzhou");
	setup();
	replace_program(ROOM);
}

