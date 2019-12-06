// Room: /xiaoyao/yaogu.c
inherit ROOM;

void create()
{
        set("short", "蛇窟");
        set("long", @LONG
这里就是外边风传的蛇窟了！白驼山弟子的驱蛇本领连丐帮帮众都
自叹不如。这里出的蛇更是见所未见，闻所未闻了！
LONG );
        set("outdoors", "xiaoyao");
        set("exits", ([
                "west" : "/d/baituo/sheku1",
        ]));
        setup();
}

void init()
{
        add_action("do_wei", "wei");
}

int do_wei(string arg)
{
        object me;
        me = this_player();
        if( me->query("family/family_name") != "白驼山派" ) return 0;
        if( !me->query_temp("job_btshan_tool") ) return 0;
        if( !objectp(present("she liang", me)) )
                return notify_fail("没有蛇粮怎么喂啊？拿自己喂蛇吗？^_^\n");
        if (!arg || (arg != "蛇" && arg != "she"))
                return notify_fail("只见群蛇蛹蛹，你竟不知怎么喂。\n");
        if(!me->query_temp("job_btshan"))
                return notify_fail("谁 叫你来这里的？？？\n");
        if( me->is_busy() )
                return notify_fail("慢慢来！别着急！！！\n");
        if( (int)me->query("qi") < 40)
                return notify_fail("你已经很努力了！休息一会吧！\n");
          message_vision("$N漫不经心的拿着蛇粮，开始喂起蛇来。。。\n",me);
        me->add("qi",-(20+random(10)));
        me->start_busy(1);
        if(random(18) < 2) {
        message_vision(HIY"$N终于把蛇给喂饱了！该向老顾交差了！\n"NOR,me);
                me->delete_temp("job_btshan");
        destruct(present("she liang", me));
        me->delete_temp("job_btshan_tool");
                me->set_temp("finish_id",1);
                tell_object(me,"你已经完成了任务！可以回去交差了。\n");
        }
        if(random(20) == 1) {
              message_vision(HIG"这群蛇真是难喂，蛇粮都喂光了！还没吃饱！\n"NOR, me);
                destruct(present("she liang", me));
        }
        if(random(15) == 1) {
                message_vision(RED"一不留神！你突然被蛇咬了一口！\n"NOR, me);
                tell_object(me, HIG "你只觉得一阵眩晕！看来中毒了！\n" NOR );
                this_player()->apply_condition("snake_poison", 30);
                message_vision(HIY"还是去找老顾吧！\n"NOR, me);
        }
        return 1;
}
