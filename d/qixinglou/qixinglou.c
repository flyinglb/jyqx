// Room: qixinglou.c

inherit ROOM;

void create()
{
        set("short", "七星楼");
        set("long", @LONG
这里是七星楼总堂的大门，不过你左看右看，就是进不去，气死了。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
            "out" :"/d/huanghe/caodi2",
            "enter" : __DIR__"dating1",
        ]));
        set("no_clean_up", 0);
        set("item_desc", ([ /* sizeof() == 2 */
            "大门":"七星楼总堂的大门。\n",
             ]));

        setup();
}
/*
void init()
{
        add_action("do_kiss","kiss");
}

int do_kiss(string arg)
{
        object me;
        me = this_player();
        if( !arg ) return 0;
        if( arg != "七星聚首" && arg != "closedoor" ) return 0;
        if( arg == "七星聚首" || arg == "closedoor" ) {
        message_vision("$N用力的敲了敲大门，一个小丫鬟把门打开，看了你几眼，小姐的朋友啊，进来吧。\n", this_player() );
        set("exits/enter", __DIR__"dating1");
        call_out("close_passage", 3);
        return 1;
        }
}

void close_passage()
{

        if( !query("exits/enter") ) return;
        delete("exits/enter");
        message("vision","龙剑说道：“来七星楼还这么慢，你别来了。\n", this_object() );
}
*/
