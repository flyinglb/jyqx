// wdroad4.c
// by Xiang

inherit ROOM;

void create()
{
	set("short", "��ʯ���");
	set("long", @LONG
������һ����ʯ����ϣ����ܾ����ĵġ�������һ������������Ǻ�
���һƬ���֡����ϻ���һ���������ӳ�����ܵ������С�
LONG );
        set("outdoors", "wudang");
	set("exits", ([
		"west"    : __DIR__"wdroad5",
		"east"    : "/d/xiaoyao/shulin3",
		"southup" : "/d/henshan/hsroad1",
		"north"   : __DIR__"wdroad3",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

