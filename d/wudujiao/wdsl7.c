// by mayue

inherit ROOM;

void create()
{
	set("short", "�嶾ɽ·");
	set("long", @LONG
�������嶾ɽ�е�ɽ��С·�����������������ϡ�ɽ·�ϼž�
������������һ˿���޵ĺۼ�����˳�ֲ�������·�е�֦������֦
��Ȼһ�������˻�ȥ������...����Ȼ��һ�����ƿ�֦�Ķ��ߡ�ǰ��
�ֳ�һ�����ߺ�ǽ������������լԺ�� 
LONG
	);
        set("outdoors", "wudujiao");

	set("exits", ([
		"east" : __DIR__"damen",
//		"south" : __DIR__"wdsl5",
		"west" : __DIR__"wdsl6",
//		"north" : __DIR__"wdsl6",
	]));
        set("objects", ([
//                "/d/npc/guojing": 1,
	]));
    

	setup();
	replace_program(ROOM);
}

