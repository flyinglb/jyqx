// /zhulin.c
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short"," 第二指节");
         set ("long",@long
这里已到了中指峰的半山腰了，由于铁掌山排列得象手指一样， 
每座山峰又分三截，就如手指的指节一般，因此这里正是位于第二
指节的位置。这里离峰顶已近，透过淡淡的云雾，似已可以看到山
路的尽头了。左前方二十于丈处，黑黝黝的似有一个洞穴，洞口砌
以玉石，修建得极是齐整。
long);
         set("outdoors","shaolin");
        set("resource/south", 1);

         set("item_desc",([
             "dong" : "一个黑黝黝的山洞。黑暗中偶尔有几点磷光闪过，好吓人。\n"
]));
         set("exits", ([
  "south" : __DIR__"sslin-5",
  "northup" : __DIR__"shanlu-8",

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
 if (arg !="dong")
              return notify_fail("你要到那去？\n");
          
             if (me->query_dex()<20) 
                    write("你试图钻进，无奈身法不够敏捷，只好做罢。\n");
            else {
                    write("你弯下腰钻进了洞里。\n");
                    message("vision",
                             me->name() + "钻进了洞里。\n",
                             environment(me), ({me}) );
              me->move(__DIR__"dong-1");
                    message("vision",
                             me->name() + "从洞里钻了出来。\n",
                             environment(me), ({me}) );
                return 1;
           }
}


