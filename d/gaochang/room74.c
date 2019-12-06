// Room: /d/gaochang/room74.c// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
        set("short", "峭壁");
        set("long", @LONG
你手抱松树，吊在位于半山腰的峭壁上。四周都是积雪，松树的根部
生着两朵海碗般大的奇花，花瓣碧绿，白中映碧，加上夕阳金光映照，娇
艳华美，奇丽万状。
LONG
        );
    if (random(10)>7)
    set("objects", ([
           __DIR__"obj/youtan":2,
    ]));
    else delete("objects");


        setup();
}
void init()
{
   object me=this_player();
   if (!wizardp(me))
        call_out("drop",3,me);
}
void drop(object me)
{
    object room;
    if (!me || environment(me)!=this_object())    return;
    if (!(room=find_object(__DIR__"room50")))
        room=load_object(__DIR__"room50");
    message_vision("只听见松树枝咔嚓一声，不堪承受$N的体重，应声而断！\n",me);
    me->move(room);
    me->receive_wound("qi",200);
    message("vision","砰的一声，"+me->name()+"惊叫着摔了下来！\n",room,({me}));
}

