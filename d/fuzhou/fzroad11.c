// Room: /d/fuzhou/fzroad11.c
// Date: May 12, 98  Java

inherit ROOM;

void create()
{
	set("short", "���д��");
	set("long", @LONG
�������ǳǽ�����������Ҳ�����������������ݵĹٻ�����
���̶��Ѷ�����������ٴ죬����һ����ζ��
LONG );
	set("exits", ([
		"east"   : __DIR__"ximen",
		"west"   : __DIR__"fzroad9",
	]));
        set("no_clean_up", 0);
	set("outdoors", "quanzhou");
	setup();
	replace_program(ROOM);
}

