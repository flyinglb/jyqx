// by mayue

inherit ROOM;

void create()
{
	set("short", "�嶾�̴���");
	set("long", @LONG
������һ����û��ɽ���еĴ�լԺ���߸ߵ�Χǽ�����Ĵ��ţ�
������һ����Ǯ�˼ҵı����Ժ�� 
LONG
	);
        set("outdoors", "wudujiao");

	set("exits", ([
		"east" : __DIR__"lianwu",
//		"south" : __DIR__"wdsl5",
		"west" : __DIR__"wdsl7",
//		"north" : __DIR__"wdsl6",
	]));
        set("objects", ([
                __DIR__"npc/jiaotu": 4,
	]));
    

	setup();
//	replace_program(ROOM);
}

