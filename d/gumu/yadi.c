 inherit ROOM;
void create()
{
        set("short", "崖底");
        set("long", @LONG
这里四面是耸立的崖壁，到处是怪石以及成堆的骸骨。也不知道是人
还是兽的，让人看了就毛骨悚然。还是快想办法离开的好 ……
LONG
        );
        setup();
}

void init()
{
        add_action("do_climb","climb");
}

int do_climb(string arg)
{
        object me = this_player();
        if( !arg || (arg!="cliff" && arg!="ya" && arg!="up") )
                return notify_fail("你要往那爬？\n");
        if( me->query("jing") < 100 )
                return notify_fail("你累的走都走不动了，怎么爬？\n");
        //if( me->query("jingli") < 100 )
        //        return notify_fail("你累的走都走不动了，怎么爬？\n");
        if( me->query("qi") < 100 )
                return notify_fail("你气血不足无法爬这么高的悬崖。\n");
        if( me->query("neili") < 100 )
                return notify_fail("你内力不足无法支持爬到崖顶。\n");
        tell_object(me,"你卯足了一口气，向崖壁一冲\n抓住了一块突起的石块，费劲的向上爬着 ……\n\n");
        me->move("/d/gumu/zhufeng");
        tell_room(environment(me),me->name()+"从崖底爬了上来 ……\n",({me}));
        return 1;
}
