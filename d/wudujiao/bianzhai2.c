// by mayue


inherit ROOM;

void create()
{
	set("short", "��կ����");
	set("long", @LONG
���������置�ؽ磬ֻ����ɽ��ˮ�㣬�羰����ԭ����ͬ��
����·�ϣ���ʱ������������Ů��·����Ұ���ظ����裬�پ���
���泩����Ը���ϴ��硣
LONG
	);
        set("outdoors", "wudujiao");

	set("exits", ([
		"east" : __DIR__"bianzhai1",
		"south" : __DIR__"bianzhai3",
//		"west" : __DIR__"bianzhai2",
//		"southeast" : __DIR__"bianzhai3",
	]));
        set("objects", ([
                 __DIR__"npc/younggirl": 2,
                 __DIR__"npc/youngboy": 1,
	]));

	setup();
	replace_program(ROOM);
}

