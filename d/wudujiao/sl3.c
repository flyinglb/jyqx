// by mayue

inherit ROOM;

void create()
{
        set("short", "������");
	set("long", @LONG
������һƬŨ�ܵ������֣�ǰ���Ѿ�û���˵�·������벻ʱ����
��������ǰ��֦�⡣���ڹ��ߺڰ����������������Լ��������� ��ֻ��
����ڵ��Ϻ�������Ϳ�֦�Ϸ�����ɳɳ����ǰ����ϡ͸��һ�������
�㲻�ɳ���������һ������
LONG
	);
        set("outdoors", "wudujiao");

	set("exits", ([
 //               "east" : __DIR__"sl3",
                "west" : __DIR__"sl2",
                "north" : __DIR__"pubu",
                "south" : __DIR__"sl5",
	]));
        set("objects", ([
//                "/d/npc/guojing": 1,
	]));
    

	setup();
	replace_program(ROOM);
}

