// Room: /d/henshan/chating.c ��ͤ
// Modified by Java on Feb.14.1998
inherit ROOM;

void create()
{
	set("short", "��ͤ");
	set("long", @LONG
����һ��·�ߵ�С��ͤ����ɽ·���˳��ڴ˴�ЪЪ�š�ͤ����
�м������Ӻͼ�֧���ʡ���Χ��һƬ���֡�
LONG );
        set("outdoors", "henshan");

	set("exits", ([
		"west"  : __DIR__"hsroad6",
	]));
	set("objects", ([
		__DIR__"npc/yuanziyi" :1,
	]));

        set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

