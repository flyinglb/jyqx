// by mayue


inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
����һ����ͨ��ũ�ң�����û��ʲô�����İ��衣ǽ�߰ڷ���һЩ
ũ�ߣ�����ֻ���ıڽԿգ�����������ԣ�� 
LONG
	);
//        set("outdoors", "wudujiao");

	set("exits", ([
		"out" : __DIR__"cun3",
//		"south" : __DIR__"minju1",
//		"west" : __DIR__"cun1",
//		"north" : __DIR__"wdsl6",
	]));
        set("objects", ([
                __DIR__"npc/cunfu": 2,
 //             __DIR__"npc/cunfu": 1,
	]));
    

	setup();
	replace_program(ROOM);
}

