// by mayue

inherit ROOM;

void create()
{
	set("short", "��ɽС·");
	set("long", @LONG
����һ����ɽ��С·����������ʯ���ɵ�̨�ף�ʪ�����ĳ�
������̦������ȫ��ï�ܵ����֡�ǰ���ƺ��Ϳ쵽Сɽ�����ˡ�
LONG
	);
        set("outdoors", "wudujiao");

	set("exits", ([
//		"northwest" : __DIR__"road3",
		"southup" : __DIR__"caoping",
//		"west" : __DIR__"wumiao",
		"northdown" : __DIR__"shanlu2",
	]));
        set("objects", ([
                __DIR__"npc/qiaofu": 2,
	]));

	setup();
	replace_program(ROOM);
}

