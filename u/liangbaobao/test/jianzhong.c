// jianzuo.c
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
        set("objects", ([
//                CLASS_D("btshan") + "/ouyangke" : 1,
//                 __DIR__"obj/jiao" : 1,
        ]));
        set("exits", ([
                  "north" : __DIR__"yongdao1",
        ]));
        set("item_desc", ([
                "剑冢" : "剑魔独孤求败既无敌于天下，乃埋剑于斯。\n",
        ]));
        set("no_clean_up", 0);
        setup();
}

void init()
{
        add_action("do_push", ({"push","break"}) );
}
int do_push(string arg)
{
        int n;
        object ob, me = this_player();

        n = this_player()->query("neili");
        if( !arg || arg != "剑冢")
        {
                write("你要推什么? \n");
                return 1;
        }
        if (me->query_temp("marks/jinshe") == "1")
        {
                if (n > 200 && query("tiesword_count") == 1)
                {
                        message_vision(
"$N又用劲全力再次推动剑冢下的碎石。堪堪又将推了三
尺，忽然叮的一声，锄头又碰到一物，拨开泥土，居然是
把黑黝黝的剑。\n", me);
                        ob = new(__DIR__"tiesword");
                        ob->move(environment(me));
                        me->set_temp("marks/jinshe", "2");
                        add("tiesword_count", -1);
                }
                else
                {
                        message_vision("$N挖不到什么，挖了几下就不想干了。\n", me);
                        me->set("neili",0);
                }
        }
        else
        {
                if (n > 100 && query("ziwei_count") == 1)
                {
                        message_vision(
"$N用力推动剑冢下的碎石 。不一会，忽然叮的一声，碰到一件铁器。
移近火把一看，见底下有块铁石，再用推了几下，拨开旁边碎石，原
来竟是一只柄锋利的剑。\n", me);
                        ob = new(__DIR__"ziwei");
                        ob->move(environment(me));
                        me->set_temp("marks/jinshe", "1");
                        add("ziwei_count", -1);
                }
                else
                {
                        message_vision("$N挖不到什么，挖了几下就不想干了。\n", me);
                        me->set("neili",0);
                }
        }
        return 1;
}
