// /zhulin.c
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short","墓室");
         set ("long",@long
这是一间墓室。墓室旁有一颗特别大的明珠闪闪发光。周围则
堆放了无数的奇珍异玩。墓室墙壁上挂这一幅画。忽然一阵阴风吹
过，你不禁打了一个寒颤。
long);
         set("outdoors","shaolin");
        set("resource/south", 1);

         set("item_desc",([
             "hua" : "一幅青年少妇的画像。\n"
]));
         set("exits", ([
             "south" : __DIR__"mushi",
]));
         setup();
}

void init()
{
        add_action("do_jump", "xian");
}

               int do_jump(string arg)
               {
                    object me;
               me = this_player();
 if (arg !="hua")
              return notify_fail("你要到那去？\n");

             if (me->query_dex()<20)
                    write("你试图钻进，无奈身法不够敏捷，只好做罢。\n");
            else {
                    write("你弯下窑钻进了画内。\n");
                    message("vision",
                             me->name() + "钻进了画。\n",
                             environment(me), ({me}) );
              me->move(__DIR__"mishi");
                    message("vision",
                             me->name() + "从画钻了出来。\n",
                             environment(me), ({me}) );
                return 1;
           }
}
