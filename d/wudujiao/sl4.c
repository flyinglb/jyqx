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
                "north" : __DIR__"sl1",
                "northeast" : __DIR__"sl2",
                "south" : __DIR__"sl6",
                "southeast" : __DIR__"sl7",
	]));
        set("objects", ([
//                "/d/npc/guojing": 1,
	]));
    

	setup();
	replace_program(ROOM);
}

