inherit ROOM;
void create()
{
        set("short", "大厅");
        set("long", @LONG
这是飘雪山庄总坛的大厅，四周富丽堂皇，你差点看花了眼，正北面放着两
把大椅。左边椅子是现任飘雪山庄庄主海妖的位置，右边是副庄主纪嫣然的。
大椅的后面是一张图画，画的是飘雪山庄的前辈两位庄主，左右擎天玉柱上
挂着一副对联（duilian)。
LONG );
        set("valid_startroom",1);
	set("no_steal", "1");
	set("no_sleep_room", "1");
        set("no_fight","1");
        set("item_desc",([
                "duilian" : "海外仙岛曾飘血，洞天福地舞神龙\n",
        ]));
        set("exits", ([
                "east"  : __DIR__"shenlong",
                "west"  : __DIR__"piaoxie",
                "out"   : "/d/city/guangchang",
        ]));
        setup();
        "/clone/board/piaoxue_b"->foo();
        }
