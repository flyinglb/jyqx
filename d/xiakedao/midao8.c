// midao8.c 密道

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "密道");
        set("long", @LONG
这是一条长长的密道，地面和石壁满是灰尘，好象很久没人来过了。
LONG );
        set("exits", ([
                "southdown" : __DIR__"midao7"
        ]));
        set("no_clean_up", 0);
        setup();
}

void init()
{
        object me = this_player();
        if( random((int)me->query_skill("dodge",1)) <= 80 && !wizardp(me) )
        {
                me->receive_damage("qi", 50);
                me->receive_wound("qi",  50);
                message_vision(HIR"$N一不小心踩到地上的一个暗纽，... 啊...！\n"NOR, me);
                me->move(__DIR__"road3");
                tell_object(me, HIR"你从山上滚了下来，只觉得浑身无处不疼，还受了几处伤。\n"NOR);
                message("vision", HIR"只见" + me->query("name") + "从山上骨碌碌地滚了下来，躺在地上半天爬不起来！\n"NOR, environment(me), me);
        }
}
