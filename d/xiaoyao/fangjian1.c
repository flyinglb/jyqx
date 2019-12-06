// fangjian1.c
// by 2000.2.29

inherit ROOM;

void create()
{
        set("short", "房间");
        set("long", @LONG
可以看出这里以前曾经是一个下棋的地方，房间除了一张石几，两只软
椅之外，空荡荡的一无所有，石几上刻着纵横十九道棋路，棋局上布着二百
多颗棋子，却是黑白对峙，竟然是一局没有下完的棋。
LONG );
        set("exits", ([
                "south" : __DIR__"shiji1",
        ]));
        set("no_clean_up", 0);
               setup();
}

void init()
{
        add_action("do_shout", "shout");
}

int do_shout(string arg)
{
        object me;
        me = this_player();

        if( !arg || arg=="" ) return 0;

        if( arg=="芝麻无门") 
        {
                tell_object(me,"你气运丹田，对着墙壁大喝一声：“芝麻无门！”\n");
                if (random(100) >50 || ((me->query("family")) && me->query("family")["master_name"]=="逍遥子"))
                {
                message("vision", "过了一会儿，你只听到一阵轰隆隆的响声，出现了一道暗门。\n", me);
                set("exits/down", __DIR__"dazuo");
                remove_call_out("close");
                call_out("close", 5, this_object());
                }
        else
                {
                message("vision", "房间里到处回荡着你的声音，震得你的耳朵翁翁作响。\n", me);
                me->receive_wound("qi",10);
                me->unconcious();
                }
                return 1;
        }
}

void close(object room)
{
        message("vision","一阵轰隆隆的响声过后，石门又缓缓地关上了。\n", room);
        room->delete("exits/down");
}


