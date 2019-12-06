#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "游戏室");
        set("long", @LONG
这里是飘雪山庄供江湖上的朋友打木人消遣的地方，
不过这里只有五个木人，拜托大家小心点打，
可别打坏了，嘿嘿要赔的哦！:)
LONG
        );
        set("outdoors", "quanzhen");
        set("exits", ([
                "south" : __DIR__"rest2",
        ]));
        set("objects", ([
                __DIR__"npc/mu-ren" : 5,
        ]));
 
        setup();
        replace_program(ROOM);
}