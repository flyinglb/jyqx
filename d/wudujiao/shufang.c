// by mayue


inherit ROOM;

void create()
{
	set("short", "�鷿");
	set("long", @LONG
�����ǽ���ƽʱ����ĵط������䲻��ֻ��������һ���鰸������
���˼����飬�����ǽ������������ġ�
LONG
	);
//      set("outdoors", "wudujiao");

	set("exits", ([
//		"east" : __DIR__"huayuan1",
//		"south" : __DIR__"jingshi",
//		"west" : __DIR__"lianwu",
		"south" : __DIR__"dating",
	]));
        set("objects", ([
                 __DIR__"obj/book1": 1,
                 __DIR__"obj/book2": 1,
	]));
    

	setup();
	replace_program(ROOM);
}

