// by mayue

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�������嶾�̴�������ĵط������濿ǽȫ�Ǳ����ܣ����������
���ֱ�����  
LONG
	);
//        set("outdoors", "wudujiao");

	set("exits", ([
//		"east" : __DIR__"bingqi",
//		"south" : __DIR__"beiyuan",
		"west" : __DIR__"beiyuan",
//		"north" : __DIR__"chufang",
	]));
        set("objects", ([
                  __DIR__"obj/ganggou": 2,
                  __DIR__"obj/woodjian": 2,
//                __DIR__"obj/tiezhui": 2,
	]));
    

	setup();
	replace_program(ROOM);
}

