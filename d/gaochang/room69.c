// Room: /u/mei/room69.c// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
int do_zuan(string arg);
int do_climb(string arg);
void create()
{
        set("short", "翡翠池");
        set("long", @LONG
这是一个四周镶满翡翠的圆池，池边长满了翠绿的青藤，看来似乎可以
爬上去。池底有一个洞(hole)。
LONG
        );
        set("item_desc", ([
        "hole" : "似乎可以钻(zuan)进去。\n",

        ]));
    set("objects", ([
               "/d/gaochang/obj/feituoarmor": 1,
]));
        setup();
}

void init()
{
        add_action("do_zuan", "zuan");
        add_action("do_climb", "climb");
//      call_out("add_per",10,this_player());
}
/*
void add_per(object me)
{
    if (!me || environment(me)!=this_object()) return;
    if (userp(me) && time()-(int)me->query_temp("per_time")>600 && (int)me->query("per")<30 && !me->query_temp("armor/cloth") ){
       tell_object(me,MAG+"你突然看到翡翠池中一个漂亮的人影对你笑了笑，你赶紧捏了自己一下，这...该不是做梦吧？"+NOR);
       me->add("per",1);
    }
    me->set_temp("per_time",time());
}
*/

int do_zuan(string arg)
{
        object me;
        me = this_player();
        if (!arg || arg !="hole"){
            write("你要钻什么？\n");
                 return 1;
            }
            {
            message("vision", me->name() + "滋溜一下不知从什么地方钻出去了。\n",
                    environment(me), ({me}) );
                     write("忽然一道暗流冲来，你脚下一个踉跄，大叫一声：不好！\n");
            me->set("qi",-1);
            me->unconcious();
            me->move(__DIR__"room43");
            message("vision", me->name() + "从瀑布里抛了出来。\n",
                    environment(me), ({me}) );
            return 1;
            }

}
int do_climb(string arg)
{
    object me;
    me = this_player();
    if( !arg || arg!="藤") return notify_fail("你要爬什么？\n");
            message("vision", me->name() + "顺着藤爬了上去。\n",
                    environment(me), ({me}) );
        me->move(__DIR__"room40");
            message_vision("$N水淋淋地爬了上来。\n", me);
        return 1;
}

