inherit ROOM;
void init();
int do_push(string);
int do_move(string);
void create()
{
        set("short", "玉峰山");
        set("long", @LONG
山峰上有斧凿痕迹，察看峰壁，洞口的痕迹很是明显，只是年深月久，
洞门(men)四周已被沙子(sand)堵塞。
LONG
        );
        set("outdoors", "room30");
        set("outdoors", "city");
        set("item_desc", ([
    "men" : "这石门看起来很重，你试试是否可以推动(push)它。\n",
    "sand" : "一些沙子。\n",
        ]));
        setup();
}
void init()
{
        add_action("do_climb", "climb");
        add_action("do_push", "push");
        add_action("do_move", "move");
}
int do_climb(string arg)
{
    object me;
    me = this_player();
    if( !arg || arg!="down") return notify_fail("你要往哪个方向爬？\n");
        me->move(__DIR__"room29");
        message("vision",
        me->name() + "战战兢兢地往下爬。\n",
                environment(me), ({me}) );
        message("vision",
        me->name() + "战战兢兢地爬了下来。\n",
                environment(me), ({me}) );
    return 1;
}
int do_move(string arg)
{
        object me;
        me = this_player();
        if (!arg || arg !="sand" )
        return notify_fail("你要推什么？\n");
        write("石门似乎动了一下。\n");
        this_player()->set_temp("marks/推1", 1);
        return 1;
}
int do_push(string arg)
{
        object me;
        object room;
        me = this_player();
    if (!arg || arg !="men"){
        write("你要推什么？\n");
        return 1;
    }
    if (!me->query_temp("marks/推1") ){
        write("你要推什么？\n");
        return 1;
    }
    if ((int)me->query_skill("force",1) < 250 ) {
        write("结果只听一声闷哼，你被石壁的反弹力震得眼前一黑....\n");
        message("vision",me->name()+"猛然一晃，急剧向下坠去。看来是凶多吉少了!\n",
            environment(me), ({me}) );
        me->move(__DIR__"room29");
            me->set("qi",-1);
        message("vision","砰！的一个人掉了下来。\n", environment(me));
        return 1;
    }
    if (!( room = find_object(__DIR__"room31")) )
            room = load_object(__DIR__"room31");
    this_player()->delete_temp("marks/推1");
    if (!query("exits/enter")){
            set("exits/enter", __DIR__"room31");
            message_vision("$N把石门推到一边，露出一个洞口，里面黑沉沉的甚么也瞧不见。\n",me);
            room -> set("exits/out", __FILE__);
            message("vision", "外面传来一阵移动石门的隆隆的响声。\n",room);
            call_out("close_door",10);
            return 1;
    }
        write("你要推什么？\n");
        return 1;
}
void close_door()
{
        object room=find_object(__DIR__"room31");
        if (!room)
        room = load_object(__DIR__"room31");
        delete("exits/enter");
        message("vision","石门轰隆一声滚回了原处，洞口又被封住了。\n",this_object());
        room -> delete("exits/out");
        message("vision","外面传来一声巨响，洞口被封住了。\n", room);
}
