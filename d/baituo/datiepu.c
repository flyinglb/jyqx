//datiepu.c

inherit ROOM;

void create()
{
        set("short", "������");
        set("long",
             "������һ�Ҵ����̣�����æ�Ŵ������Ʊ����������������͡�\n"
        );
        set("exits", ([
                "north" : __DIR__"dongjie",
        ]));
	set("objects",([
		__DIR__"npc/smith" : 1,
	]));
//        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

