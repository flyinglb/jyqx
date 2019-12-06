// Room: /u/mei/room29.c// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
        set("short", "玉峰山脚");
        set("long", @LONG
玉峰近看尤其美丽，通体雪白，莹光纯净，做玉匠的只要找到小小的一块
白玉，已然终身吃着不尽，哪知这里竟有这样一座白玉山峰。抬头仰望，只觉
心旷神怡，万虑俱消，暗暗赞叹造物之奇。
LONG
        );
        set("no_new_clean_up", 0);
        set("outdoors", "room29");
        set("item_desc", ([
        "白玉山峰":   
"     峰上布满斧凿痕迹，看来似乎可以爬(climb)上去。\n",
]));
        set("exits", ([ /* sizeof() == 2 */
        "south" : __DIR__"room27",
]));
        setup();
}
void init()
{
        add_action("do_climb", "climb");
}
int do_climb(string arg)
{
    object me;
    me = this_player();
    if( !arg || arg!="up") return notify_fail("你要往哪个方向爬？\n");
        me->move(__DIR__"room30");
        message("vision",
        me->name() + "战战兢兢地，气喘嘘嘘地往上爬。\n",
                environment(me), ({me}) );
        message("vision",
        me->name() + "气喘嘘嘘地爬了上来。\n",
                environment(me), ({me}) );
    return 1;
}
