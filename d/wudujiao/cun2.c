// by mayue

inherit ROOM;

void create()
{
	set("short", "С��");
	set("long", @LONG
����С���ʯ��·�ϣ����Զ�������ʯ���ɵķ��ݡ������ﾲ���ĵģ�
���������ˣ�ż������һ�������С� 
LONG
	);
       set("outdoors", "wudujiao");

	set("exits", ([
		"east" : __DIR__"cun3",
		"south" : __DIR__"minju1",
		"west" : __DIR__"cun1",
//		"north" : __DIR__"wdsl6",
	]));
        set("objects", ([
//                "/d/npc/guojing": 1,
	]));
    

	setup();
//	replace_program(ROOM);
}

