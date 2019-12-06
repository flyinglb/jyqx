#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "练功房");
        set("long", @LONG
这间是拇指小叶的练功房，屋中没有什么陈
设，只有几个蒲团和木人供练功和打坐之用。
LONG);
        set("exits", ([
                "south" : __DIR__"huiyi",
                "north" : __DIR__"sleep3",
        ]));

        set("objects", ([
                __DIR__"npc/mu-ren" : 5,
        ]));

        setup();
        replace_program(ROOM);
}
