// by mayue

inherit ROOM;

void create()
{
	set("short", "����С·");
	set("long", @LONG
�������һ����ߵ�һ������С·��һ�Ծ����峺�Ľ�ˮ���а�
���಻�ϵ��һ�������ϼ������Ϯ�ˣ���������۷��ڻ�������衣
LONG
	);
        set("outdoors", "wudujiao");

	set("exits", ([
//		"southeast" : __DIR__"xiaolu",
		"southeast" : __DIR__"xiao3",
//		"west" : __DIR__"wumiao",
		"north" : __DIR__"xiao1",
	]));
        set("objects", ([
//                "/d/npc/guojing": 1,
	]));
   

	setup();
	replace_program(ROOM);
}

