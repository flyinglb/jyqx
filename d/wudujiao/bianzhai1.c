// by mayue


inherit ROOM;

void create()
{
	set("short", "��կ����");
	set("long", @LONG
���������置�ؽ磬ֻ����ɽ��ˮ�㣬�羰����ԭ����ͬ��
����·�ϣ���ʱ������������Ů��·����Ұ���ظ����裬�پ���
���泩����Ը���ϴ��硣������������ĺ�ɭ���ˡ�
LONG
	);
        set("outdoors", "wudujiao");

	set("exits", ([
//		"east" : __DIR__"milin4",
		"south" : __DIR__"milin8",
		"west" : __DIR__"bianzhai2",
		"southwest" : __DIR__"bianzhai3",
	]));
        set("objects", ([
//                "/d/npc/guojing": 1,
	]));

	setup();
//	replace_program(ROOM);
}

