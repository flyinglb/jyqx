#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "练功房");
        set("long", @LONG
这里是飘雪的弟子练功的地方，
不是飘雪的弟子千万别在这里呆太久哦！
因为庄主有令，如在各大堂发现非飘雪的
人物，格杀无论，
LONG);
        set("exits", ([
                "north" : __DIR__"dayuan1",
        ]));

        set("objects", ([
                __DIR__"npc/mu-ren" : 5,
        ]));

        setup();
        replace_program(ROOM);
}