// Room: /d/henshan/hsroad8.c �ּ��
// Modified by Java on Feb.14.1998
inherit ROOM;

void create()
{
	set("short", "�ּ��");
	set("long", @LONG
������һ���ּ�С���������������ѡ�����������һ������·����
��ĵ�·Ҫ��һЩ��
LONG );
        set("outdoors", "henshan");

	set("exits", ([
		"northwest" :"/d/wudang/wdroad9",
		"south"     : __DIR__"hsroad7",
	]));

        set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

