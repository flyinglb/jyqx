// Room: /u/mei/room68.c// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
        set("short", "翠谷");
        set("long", @LONG
向西去了二里多，只见峭壁上有一道大瀑布冲击而下，料想是雪
融而成，阳光照射下犹如一条大玉龙，极是壮丽。瀑布泻在一座清澈
碧绿的深潭之中，潭水却也不见满，当是另有泄水的去路。
LONG
        );
        set("no_new_clean_up", 0);
        set("exits", ([ 
  "east" : __DIR__"room67",
]));
        set("outdoors", "city");
        set("item_desc", ([
        "峭壁" : "峭壁上有一小山洞(cave)，似乎可以钻(zuan)进去。\n", 
        "cave" : "黑黢黢的山洞里飘出一阵阴风，吓得你直打哆嗦。\n",
        "深潭" : "潭中游着许多小白鱼。\n", 
])); 
        set("objects",([
        __DIR__"npc/monkey1":1,
        ]));

        setup();
}
void init()
{
   add_action("do_zuan","zuan");
}

int do_zuan(string arg)
{

    object me = this_player();
//    int dex = this_player()->query_dex();
//    object ob;

    if (arg != "cave" && arg != "out") return notify_fail("你怎么没事老爱钻洞呀?\n");
    if (me->query("age")>16) return notify_fail("这么小的洞看来只有小孩才能钻得进去!\n");
        message("vision", me->name() + "滋溜一下钻了进去。\n",
                environment(me), ({me}) );
    me->move(__DIR__"room66");
        message("vision", me->name() + "从石缝里钻了出来。\n",
                environment(me), ({me}) );
    return 1;
}

