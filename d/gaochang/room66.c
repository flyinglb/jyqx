// Room: /u/mei/room66.c// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
        set("short", "峭壁");
        set("long", @LONG
眼前茫茫云海，更无去路，竟是置身在一个三面皆空的极高平台，
另一面是一仞耸天的峭壁。平台倒有十余丈方圆，可是半天临空，上
既不得，下又不能，当真是死路一条。这大平台上白皑皑的都是冰雪，
既无树林，更无野兽。
LONG
        );

        set("outdoors", "city");
        set("item_desc", ([
        "峭壁" : "峭壁上有一小山洞(cave)，似乎可以钻(zuan)进去。\n", 
        "cave" : "黑黢黢的山洞里飘出一阵阴风，吓得你直打哆嗦。\n",
])); 
        set("outdoors", "room63");
    setup();
}

void init()
{
   add_action("do_jump","jump");
   add_action("do_zuan","zuan");
}
int do_jump(string arg)
    {
        object me,room;
        me = this_player();
        if( !arg || arg!="down") return notify_fail("你要往哪跳？\n");
          message_vision("$N犹豫了一下，鼓气勇气，跳了下去。\n",me);
        if ((int)me->query_skill("dodge",1) < 300 ) {
          message("vision",me->name()+"急剧向下坠去。看来是凶多吉少了!\n",
            environment(me), ({me}) );
        if (!room=find_object(__DIR__"room63"))
                room=load_object(__DIR__"room63");
        me->move(room);
        message("vision","砰！的一个人掉了下来。\n",room,({me}));
        me->set_temp("die_for","坠崖");
        me->die();
        return 1;
        }
        message("vision",
        me->name() + "犹豫了一下，鼓气勇气，跳了下去。\n“嘭”的一巨响，似乎听到"+me->name()+"惨嚎了一声!\n",
        environment(me), ({me}) );
        if (!room=find_object(__DIR__"room63"))
                room=load_object(__DIR__"room63");
        me->move(room);
        message("vision","砰！的一个人掉了下来。\n",room,({me}));
        return 1;
     }
int do_zuan(string arg)
{

    object me = this_player();
    object room;

    if (arg != "cave" && arg != "out") return notify_fail("你怎么没事老爱钻洞呀?\n");
    if (me->query("age")>16) return notify_fail("这么小的洞看来只有小孩才能钻得进去!\n");
    if (me->query("str")>18) return notify_fail("你的身体太壮了，钻不进这么小的洞！\n");
        message("vision", me->name() + "滋溜一下钻了进去。\n",
                environment(me), ({me}) );
        if (!room=find_object(__DIR__"room67"))
                room=load_object(__DIR__"room67");
        me->move(room);
        message("vision", me->name() + "从石缝里钻了出来。\n",
                room, ({me}) );
    return 1;
}

