// /guanwai/xiaoxiang.c

inherit ROOM;

void create()
{
	set("short", "С��");
	set("long", @LONG
����һ��Ƨ�������С����ܼž�������һ����ӰҲû�С�������ʯ
��·������һ����Ļ�ѩ�����ڽ��·�������֨����������С��ľ�ͷ��
һ�����ݡ�
LONG );
	set("exits", ([
		"south" : __DIR__"tuwu",
		"east"  : __DIR__"beicheng",
	]));
	set("no_clean_up", 0);
	set("outdoors", "guanwai");
	setup();
	replace_program(ROOM);
}

