// Room: chufang.c
inherit ROOM;

void create()
{
	set("short", "厨房");
	set("long", @LONG
这是黑木崖的厨房，中央摆着大圆桌，周围则放着几张竹椅。
日月神教的弟子都在这里用餐。
LONG );
	set("exits",([
	    "west" :__DIR__"chengdedian",
	]));
	set("objects",([
		"/clone/food/jitui" : 6,
		"/clone/food/jiudai" : 2,
        ]));

        set("no_fight", 1);
        setup();
	replace_program(ROOM);
}

