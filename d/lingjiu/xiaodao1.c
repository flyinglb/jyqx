//ROOM xiaodao1.c

inherit ROOM;

void create()
{
	set("short", "С��");
        set("long",@LONG
һ��С���������۵�ͨ��Զ��, �����������де����֣�΢�紵����
��Ҷ����������������
LONG );
	set("outdoors", "lingjiu");
        set("exits", ([
            "north" : __DIR__"xiaodao2",
            "south" : __DIR__"huayuan",
        ]));
        set("objects",([
            "/d/baituo/npc/cungu" : 1,
	]));
//        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
