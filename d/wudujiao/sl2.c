// by mayue

inherit ROOM;

void create()
{
        set("short", "������");
	set("long", @LONG
������һƬŨ�ܵ������֣�ǰ���Ѿ�û���˵�·������벻ʱ����
��������ǰ��֦�⡣���ڹ��ߺڰ����������������Լ��������� ��ֻ��
����ڵ��Ϻ�������Ϳ�֦�Ϸ�����ɳɳ����
LONG
	);
        set("outdoors", "wudujiao");

	set("exits", ([
                "east" : __DIR__"sl3",
                "southwest" : __DIR__"sl4",
                "west" : __DIR__"sl1",
                "southeast" : __DIR__"sl5",
	]));
        set("objects", ([
//                "/d/npc/guojing": 1,
	]));
    

	setup();
	replace_program(ROOM);
}

