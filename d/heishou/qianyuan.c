inherit ROOM;
void create()
{
        set("short", "前院");
        set("long", @LONG
这里是五指山庄的前院，相当宽敞。左右靠墙各建有几间低矮
的平房，像是家人的住处。正前方几棵树木，湖中清风吹来，落叶
萧萧而下。树木再往后是一间大厅。
LONG );
        set("no_sleep_room", "1");
        set("no_clean_up", 0);
        set("exits", ([
                "west"  : __DIR__"shufang",
                "east"  : __DIR__"lgong",
                "out"  : __DIR__"damen",
                "north"  : __DIR__"dating1",
        ]));
        setup();
}
