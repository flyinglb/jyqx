//ROOM xiaodao2.c

inherit ROOM;

void create()
{
	set("short", "С��");
        set("long",@LONG
һ��С���������۵�ͨ��Զ��, �����������де����֣�΢�紵����
��Ҷ��������������. 
LONG );
	set("outdoors", "lingjiu");
        set("exits", ([
            "north" : __DIR__"men3",
            "south" : __DIR__"xiaodao1",
        ]));
        set("objects",([
            "/d/baituo/npc/cungu" : 2,
        ]));
//        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
