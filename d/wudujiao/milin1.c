// by mayue

inherit ROOM;

void create()
{
	set("short", "��ɭ��");
	set("long", @LONG
������������ĺ�ɭ�֣����ܾ���ï�ܵĴ��֣��޴�Ĺ�ľ��
����գ�ͷ��������һƬ��ա����²�ʱ������΢�����죬�ƺ���
ʲô�����Ӳݴ����ι���Զ��ż������һ��Ұ�޵ĺ�������
LONG
	);
        set("outdoors", "wudujiao");

	set("exits", ([
		"east" : __DIR__"milin2",
		"south" : __DIR__"milin2",
		"west" : __DIR__"milin2",
		"north" : __DIR__"shanlu1",
	]));
        set("objects", ([
//                "/d/wudujiao/npc/cunmin": 1,
//               "/d/wudujiao/npc/cunfu": 1,
	]));

	setup();
	replace_program(ROOM);
}

