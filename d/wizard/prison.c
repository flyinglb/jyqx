// /d/wizard/prison.c 监狱，用来惩罚捣乱的玩家
// byp@MX

#include <ansi.h>
inherit ROOM;

void check_release(object me);

void create()
{
        set("short", "黑狱");
        set("long", @LONG
这里黑呼呼的你什么也看不清，四下里发出一阵难闻的恶臭。这里是巫师
专门用来惩罚那些捣乱玩家的。看来你是得在这呆上一阵子了。还是老老实实
闭门思过吧！
LONG
        );
        set("no_fight",1);
        set("no_get",1);
        set("no_beg",1);
        set("no_steal",1);
        set("no_get_from",1);
        set("no_beg_from",1);
        set("no_steal_from",1);
        set("no_clean_up", 0);

        setup();
}
void init()
{
        object me = this_player();
        if(wizardp(me)) return;
        if( !me->query("prison")
        || ((int)me->query("prison/release_time") < 1) ) {
                me->delete("prison");
                me->move("/d/city/wumiao");
                me->set("startroom","/d/city/wumiao");
                message("vision", "你忽然发现前面多了一个人影，不过那人影又好像已经在那里\n"
                "很久了，只是你一直没发觉。\n", environment(me), me);
        } else me->set("startroom","/d/wizard/prison");
}
