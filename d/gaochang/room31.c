inherit ROOM;
int do_use(string arg);
int do_tiao(string arg);
void create()
{
        set("short", "甬道");
        set("long", @LONG
这个山洞里伸手不见五指，黑沉沉的甚么也瞧不见。
LONG
        );
        setup();
}
void init()
{
        add_action("do_use", "use");
        add_action("do_tiao", "tiao");
}
int do_use(string arg)
{
        object me;
        me = this_player();
        if( !arg || arg=="" ) return 0;
        if (!present("fire", me))  return 0;
        if( arg=="fire" ) {
             write(
"    取出火折一晃，吓了一跳，原来下去到地有十七八丈高，峰内地面远
比外面的为低。\n"
             );
        set("long", @LONG
凭借火折的微光，你可以看到从这下去到地有十七八丈高，峰内地面远
比外面的为低。
LONG
        );
             this_player()->set_temp("marks/跳1", 1);
             return 1;
       }
}
int do_tiao(string arg)
{
        object me,ob;
        me = this_player();
        if (me->query_temp("marks/跳1") ) {
        if( !arg || arg!="down") return notify_fail("你要往哪跳？\n");          
        write("你犹豫了一下，鼓气勇气，跳了下去。\n");
    if ((int)me->query_skill("dodge",1) < 300 ) {
        message("vision",me->name()+"急剧向下坠去。看来是凶多吉少了!\n",
            environment(me), ({me}) );
        me->unconcious();
       me->receive_wound("qi", 200);
        me->move(__DIR__"room32");
        message("vision","砰！的一个人掉了下来。\n", environment(me));
        return 1;
        }
            message("vision", me->name() + "“嗖”地一声跳了下去。\n",
                    environment(me), ({me}) );
            me->move(__DIR__"room32");
            message("vision", me->name() + "从上面跳了下来。\n",
                    environment(me), ({me}) );
            this_player()->delete_temp("marks/跳1");
           if ( objectp(ob=present("fire", this_player())) )     {
            message_vision("$N手一松, 火折子不知掉到那了。\n", me);
            destruct(ob);
            return 1;
           }
        } else {
            write("你想往哪儿跳?!\n");
            return 1;
        }
}
