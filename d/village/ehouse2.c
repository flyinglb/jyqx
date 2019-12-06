// Room: ehouse2.c

inherit ROOM;

void create()
{
        set("short", "民宅");
        set("long", @LONG
这是一间很结实的房子，虽然也是间土坯房，但看的出建造的比村里
其他的土坯房要好很多。墙上挂着、地下摆着一些农具。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
        "south" :__DIR__"eroad2",
        "enter" : "/d/heishou/damen",
        ]) );

        set("objects", ([
                __DIR__"npc/dibao": 1
        ]) );
        set("no_clean_up", 0);

        setup();
}
/*

void init()
{
        add_action("do_want","want");
}

int do_want(string arg)
{
        object me;
        me = this_player();
        if( !arg ) return 0;
        if( arg != "杀人"  ) return 0;
        if( arg == "杀人"  ) {
        message_vision("$N对着地保不知道说了些什么！\n ", this_player() );
message_vision("地保很Cool地对$N说道：“想买凶杀人，你找对地方了，进来吧！\n",this_player() );
        set("exits/enter", "/u/liangbaobao/heishou/damen");
        call_out("close_passage", 3);
        return 1;
        }
}

void close_passage()
{

        if( !query("exits/enter") ) return;
        message_vision("没钱还想买凶杀人，算了吧,地保一下就把门关了起来。\n ", this_player() );
        delete("exits/enter");
}
*/
