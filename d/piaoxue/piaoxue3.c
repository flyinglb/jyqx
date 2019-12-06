inherit ROOM;
void create()
{
        set("short", "飘雪楼二楼");
        set("long", @LONG
这里是飘雪山庄的两位庄主住的地方，东面是副庄主纪嫣然
的寝殿，西面是庄主海妖的寝殿，如果您不是这里的庄主最
好还是尽快离开。否则招惹了主人可不是什么好玩的事情。
LONG );
	set("no_steal", "1");
	set("no_sleep_room", "1");
        set("no_fight","1"); 
	set("no_clean_up", 0);
	        set("exits", ([
                "east"  : __DIR__"yanran",
                "west"  : __DIR__"haiyao",
                "down"  : __DIR__"piaoxue2",
        ]));
        setup();
}