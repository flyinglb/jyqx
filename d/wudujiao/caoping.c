// by mayue

inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
ɽ����һ��Ƭ�����أ�����������Ʈ�ż�����ƣ���������
���͵Ĳݵأ�ǳǳ�ĸպÿ��Ըǹ�����,ɢ����һ�����˵ķ���
�������ֱ��������������ǰ���м����ª�����ᡣ
LONG
	);
        set("outdoors", "wudujiao");

	set("exits", ([
//		"northwest" : __DIR__"road3",
		"south" : __DIR__"zhushe",
//		"west" : __DIR__"wumiao",
		"northdown" : __DIR__"shanlu3",
	]));
        set("objects", ([
//                "/d/npc/guojing": 1,
	]));

	setup();
	replace_program(ROOM);
}

