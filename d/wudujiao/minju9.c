// by mayue


inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����������ڵͰ��Ĺ������棬���ܵ������ǻҳ���֩������
��һ̧ͷ�ͻ��������档�������ܱ�����Ĳ�����ס�ˣ��㿴��
����������������Ҳ���ֲ����㡣 
LONG
	);
//        set("outdoors", "wudujiao");

	set("exits", ([
		"out" : __DIR__"minju7",
//		"south" : __DIR__"minju1",
//		"west" : __DIR__"cun1",
//		"north" : __DIR__"wdsl6",
	]));
        set("objects", ([
//                __DIR__"npc/xuetong": 3,
                  __DIR__"npc/zhanglang": 1,
	]));
	setup();
	replace_program(ROOM);
}
