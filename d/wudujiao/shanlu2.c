// by mayue

inherit ROOM;

void create()
{
	set("short", "��ɽС·");
	set("long", @LONG
����һ����ɽ��С·����������ʯ���ɵ�̨�ף�ʪ�����ĳ�
������̦������ȫ��ï�ܵ����֡�Զ������һ�������ɽ������
LONG
	);
        set("outdoors", "wudujiao");

	set("exits", ([
//		"northwest" : __DIR__"road3",
		"southup" : __DIR__"shanlu3",
//		"west" : __DIR__"wumiao",
		"northdown" : __DIR__"xiaolu",
	]));
        set("objects", ([
//                "/d/npc/guojing": 1,
	]));

	setup();
	replace_program(ROOM);
}

