// jianzhong.c
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "剑冢");
        set("long", @LONG   
洞后树木苍翠，山气清佳，便信步过去观赏风景，行里
许，来到一座峭壁之前。那峭壁便如一座极大的屏风，冲天
而起，峭壁中部离地约二十余丈处，生着一块三四丈见方的
大石，便似一个平台，石上隐隐刻得有字。极目上望，瞧清
楚是“剑冢”两个大字
LONG
        );
        set("outdoors", "city");
        set("exits", ([
                  "north" : __DIR__"yongdao1",
                  "west" : __DIR__"xibian",
        ]));
        set("item_desc", ([
                "剑冢" : "剑魔独孤求败既无敌于天下，乃埋剑于斯。\n",
        ]));

        set("tiesword_count",random(10)-7);
        set("ziwei_count",random(10)-6);
        setup();
}

void init()
{
        add_action("do_push", ({"push","break"}) );
}

int do_push(string arg)
{
        object ob, me = this_player();
        int n = me->query("neili");
        
        if( !arg || arg!="剑冢" ) {
                write("你要推什么? \n");
                return 1;
        }
        if( n<200 ) {
                write("你已经没有力气在推了。\n");
                return 1;
        }
        
        if (me->query_temp("tmark/玄") == 1) {
                if (n > 200 && query("tiesword_count") > 0)
                {
                        message_vision(
"$N又用劲全力再次推动剑冢下的碎石。堪堪又将推了三
尺，忽然叮的一声，锄头又碰到一物，拨开泥土，居然是
把黑黝黝的剑。\n", me);
                        ob = new(__DIR__"/obj/tiesword");
                        if(!ob->move(me)) ob->move(environment(me));
CHANNEL_D->do_channel(this_object(),"rumor",me->name()+"得到了古墓重宝--玄铁剑。\n");
                        set("tiesword_count", 0);
                } else {
                        message_vision("$N挖了几下，什么也没有挖到。\n", me);
                }
        } else {
                if (n > 200 && query("ziwei_count") > 0) {
                        message_vision(
"$N用力推动剑冢下的碎石 。不一会，忽然叮的一声，碰到一件铁器。
移近火把一看，见底下有块铁石，再用推了几下，拨开旁边碎石，原
来竟是一只柄锋利的剑。\n", me);
                        ob = new(__DIR__"/obj/ziwei");
                        if(!ob->move(me)) ob->move(environment(me));
CHANNEL_D->do_channel(this_object(),"rumor",me->name()+"得到了古墓重宝--紫薇软剑。\n");
                        me->set_temp("tmark/玄", 1);
                        set("ziwei_count", 0);
                } else {
                        message_vision("$N挖了几下，什么也没有挖到。\n", me);
                }
        }
        me->add("neili",-50);
        return 1;
}

int valid_leave(object me, string dir)
{
    mapping myfam;
    me = this_player();
    myfam = (mapping)me->query("family");
    if ((!myfam || (myfam["family_name"] != "古墓派")) && (dir == "west"))
      return notify_fail("非古墓派弟子，到此止步吧。\n");
    else  return 1;
}
