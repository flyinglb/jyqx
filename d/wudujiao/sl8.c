// by mayue

inherit ROOM;

void create()
{
        set("short", "������");
	set("long", @LONG
������һƬŨ�ܵ������֣�ǰ���Ѿ�û���˵�·������벻ʱ����
��������ǰ��֦�⡣��Զ��һ��ǧ��Ĺ���ֱ���������������ݺύ��
�������ƺ���������˵���ƾõ����¡����ڹ��ߺڰ�����������������
���������� ��ֻ������ڵ��Ϻ�������Ϳ�֦�Ϸ�����ɳɳ����ǰ��
��ϡ͸��һ˿�������㲻�ɸ��˵Ľ��߼�����
LONG
	);
        set("outdoors", "wudujiao");

	set("exits", ([
                "north" : __DIR__"sl5",
 //               "southwest" : __DIR__"sl4",
                "west" : __DIR__"sl7",
 //               "southeast" : __DIR__"sl5",
	]));
        set("objects", ([
//                "/d/npc/guojing": 1,
	]));
    

	setup();
	replace_program(ROOM);
}

