// Room: /d/fuzhou/fzroad6.c
// Date: May 12, 98  Java

inherit ROOM;

void create()
{
	set("short", "���ӹŵ�");
	set("long", @LONG
����������������ɽ�������������Ĺ���̣����ղ�����⡣
ɽ�ж������޳�û�޳�����·������һ���ֺ�����վ�ڵ�����
LONG );
	set("exits", ([
		"westdown" : __DIR__"fzroad7",
		"eastdown" : __DIR__"fzroad5",
	]));
        set("objects", ([
		"/d/qingcheng/npc/yu" : 1,
	]));
	set("outdoors", "quanzhou");
	setup();
	replace_program(ROOM);
}

