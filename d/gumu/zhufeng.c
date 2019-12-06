// zhufeng.c
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "终南山主峰");
        set("long", @LONG
此时你已身在终南山主峰，视野更为广阔。往低望去，群山尽皆
匍匐在脚下。重阳宫的翠绿琉瓦在山腰处，晶莹生辉。只见不少殿宇
散布於山坳间，景色颇为美妙。一块巨石 (shi)立在一旁，似乎刻了
什麽东西。往西和南各是一条山路。
LONG
        );
        set("item_desc", ([
                "shi"  :
"
                於人妄矫重异要佐子
                今传迹矫阳人伴汉房
                终入复英起与赤开志
                南道知雄全异松鸿亡
                山初非姿真书游举秦
                ，，，，，，，，，
                殿二收乘高造功屹曾
                阁仙心时视物成然进
                凌此活或仍不拂天桥
                烟相死割阔轻衣一下
                雾遇墓据步付去柱履
                。。。。。。。。。
"
        ]));
        set("outdoors", "gumu");
        set("exits", ([
                "westdown"  : __DIR__"shanlu2",
                "southdown" : __DIR__"shanlu1",
        ]));

        setup();
}

void init()
{
        add_action("do_climb", "climb");
        add_action("do_jump","jump");
}

int do_climb(string arg)
{
        object me = this_player();
        
        if( !arg || (arg!="cliff" && arg!="ya" && arg!="down") )
                return 0;
        
        if( me->query("family/family_name") != "古墓派" 
        || me->query("family/master_name") != "杨过" )
                return notify_fail("你试着向崖壁爬下去，可是怎么也没法找到向下爬的办法。\n");
        
        tell_room(environment(me),me->name()+"一转身，向着崖壁爬下去　……\n",({me}));
        tell_object(me,"你顺着山藤慢慢的向着崖壁下爬去　……\n\n");
        me->move(__DIR__"shibi");
        tell_room(environment(me),me->name()+"从崖壁上爬了下来　……\n",({me}));
        return 1;

}

int do_jump(string arg)
{
        object me = this_player();
        string msg1, msg2, msg3, msg4;
        
        if( !arg || (arg!="cliff" && arg!="ya" && arg!="down") )
                return 0;
        
        msg1 = HIY+me->name()+"不知为什么突然向山崖跳去 ……\n"
                + "只听隐约似乎传来一声惨叫“啊~~~~~~！”\n";
                
        msg2 = HIY"你不故一切的向山崖一跳 ……\n"
                + "只听耳边只有呼呼的风声，脚下是蒙蒙迷雾 ……\n"
                + "你不禁吓得大叫 “啊~~~~~~！”\n"
                + "接着你的眼前一黑 ……\n\n"NOR;
                
        msg3 = HIY"你不故一切的向山崖一跳 ……\n"
                + "只听耳边只有呼呼的风声，脚下是蒙蒙迷雾 ……\n"
                + "你不禁吓得大叫 “啊~~~~~~！”\n"
                + "忽的你身体似乎碰到了什么，你一阵乱抓 ……\n\n"NOR;
                
        msg4 = HIY"你不故一切的向山崖一跳 ……\n"
                + "只听耳边只有呼呼的风声，脚下是蒙蒙迷雾 ……\n"
                + "你不禁豪气顿生，引声长啸 ~~~~~~！\n"
                + "忽然你灵巧的一转身，一把抓住山藤 ……\n\n"NOR;


        if( me->query("family/family_name") != "古墓派" ) {
                tell_room(environment(me),
                msg1 + "接着好象是重物坠地的声音“咚”……\n"
                + "你在听了一会，可惜什么也听不到了 ……\n"+NOR
                ,({ me }));
                tell_object(me,msg2);
                me->move(__DIR__"yadi");
                me->die();
                return 1;
        } 
        
        msg1 += "你在听了一会，可惜什么也听不到了 ……\n"+NOR;
        
        if( me->query("combat_exp") < 30000 ) {
                tell_room(environment(me), msg1,({me}));
                tell_object(me, msg3);
        } else {
                tell_room(environment(me), msg1,({me}));
                tell_object(me, msg4);
        }
        me->move(__DIR__"shibi");
        tell_room(environment(me),me->name()+"从崖壁上跳了进来　……\n",({me}));
        return 1;
}
