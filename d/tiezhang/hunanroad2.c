// /d/xiangyang/hunanroad2.c

inherit ROOM;

void create()
{
	set("short", "��·");
	set("long", @LONG
����������������·�ϣ�ż��������������ҴҶ����������Ѿ��Ǻ���
�ؽ磬����������������ڡ��ϱ���һ��С��
LONG
	);
        set("outdoors", "tiezhang");

	set("exits", ([
		"northeast" : __DIR__"hunanroad1",
		"south" : "/d/tiezhang/lx",
	]));

	setup();
	replace_program(ROOM);
}


