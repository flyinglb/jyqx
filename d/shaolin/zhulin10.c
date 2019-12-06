// /zhulin.c
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short","竹林");
         set ("long",@long
这是一片密密的竹林(zhulin)。这里人迹罕至，惟闻足底叩击
路面，有僧敲木鱼声；微风吹拂竹叶，又如簌簌禅唱。令人尘心为
之一涤，真是绝佳的禅修所在。
long);
         set("outdoors","shaolin");
        set("resource/south", 1);

         set("item_desc",([
             "zhulin" : "这是一片密密的竹林。\n"
]));
         set("exits", ([
             "south" : __DIR__"zhulin6",
]));
         setup();
}

void init()
{
        add_action("do_jump", "zuan");
}

               int do_jump(string arg)
               {
                    object me;
               me = this_player();
 if (arg !="zhulin")
              return notify_fail("你要到那去？\n");
          
             if (me->query_dex()<20) 
                    write("你试图钻进，无奈身法不够敏捷，只好做罢。\n");
            else {
                    write("你弯下窑钻进了密林。\n");
                    message("vision",
                             me->name() + "钻进了密林。\n",
                             environment(me), ({me}) );
              me->move(__DIR__"linnei");
                    message("vision",
                             me->name() + "从密林钻了出来。\n",
                             environment(me), ({me}) );
                return 1;
           }
}

