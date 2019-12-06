inherit ROOM;
void create()
{
        set("short", "飘雪楼二楼");
        set("long", @LONG
这里是飘雪山庄的执法中心，在这里立着一个木牌(sign)
，东西是是长老院，南面是飘雪山庄的护法堂，北面是执法
堂，是用来处理犯了庄规的弟子的，如果您不是犯戒的飘雪
弟子请尽快离开。
LONG );
	set("no_steal", "1");
	set("no_sleep_room", "1");
        set("no_fight","1"); 
	set("no_clean_up", 0);
	set("item_desc",([
                "sign" : "长老院重地，不得擅闯\n",
        ]));
        set("exits", ([
                "east"  : __DIR__"oldguy1",
                "west"  : __DIR__"oldguy2",
                "south"  : __DIR__"hufa",
                "north"  : __DIR__"zhifa",
                "up"  : __DIR__"piaoxue3",
                "down"  : __DIR__"piaoxue",
        ]));
        setup();
}