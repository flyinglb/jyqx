//room: huayuan.c
inherit ROOM;

void create()
{
        set("short","��԰");
        set("long",@LONG
�����԰��Ȼ���󣬵�����ľ������������ĳ���������һ������
Ѿ������������Ϸ���������������Ļ���������ͬ�������
LONG );
        set("outdoors", "yanziwu");
        set("exits",([
            "north" : __DIR__"changlang",
            "south" : __DIR__"jiashan",
            "west"  : __DIR__"dannuo",
            "east"  : __DIR__"biheqiao",
        ]));
        set("objects",([
            __DIR__"npc/yahuan" : 2,
        ]));
//        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

