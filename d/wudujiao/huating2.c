// by mayue

inherit ROOM;

void create()
{
	set("short", "�ܷ�ͤ");
	set("long", @LONG
������һ����԰�е�Сͤ�ӣ�������������ɫ���㡣ͤ�ӵ������ż���ľ�ˡ�
LONG
	);
//       set("outdoors", "wudujiao");

	set("exits", ([
//		"east" : __DIR__"huating",
//		"south" : __DIR__"huating2",
		"west" : __DIR__"huayuan2",
		"north" : __DIR__"huating1",
	]));
        set("objects", ([
                 "/d/shaolin/obj/mu-ren": 4,
	]));
    

	setup();
	replace_program(ROOM);
}

