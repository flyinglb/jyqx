// Room: /d/henshan/hsroad7.c �ּ���
// Modified by Java on Feb.14.1998
inherit ROOM;

void create()
{
	set("short", "�ּ���");
	set("long", @LONG
������һ���ּ����������������ѡ������Ǻ������ڡ��ϱ���
���ϡ�
LONG );
        set("outdoors", "henshan");

	set("exits", ([
		"north"  : __DIR__"hsroad8",
		"south"  : __DIR__"hsroad6",
	]));
	set("objects", ([
		"/d/village/npc/dog" : 1,
	]));

        set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

