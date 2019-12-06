inherit ROOM;
void create()
{
        set("short", "神龙殿");
        set("long", @LONG
这是飘雪山庄大厅东面的神龙殿，聚集着各路江湖豪杰，四周依旧富丽堂皇，
墙上挂着一副对联(duilian)。西北面就是飘雪山庄的中心，飘雪楼的所在，
如果非飘雪弟子千万不要进入，再往西，是飘雪山庄的客房，还有供英雄们
消遣用的木人。
LONG );
	set("no_steal", "1");
	set("no_sleep_room", "1");
        set("no_fight","1"); 
	set("no_clean_up", 0);
        set("item_desc",([
                "duilian" : "天罡神龙三百万，静观江湖任是非\n",
        ]));
        set("exits", ([
                "east"  : __DIR__"rest1",
                "west"  : __DIR__"dating",
                "northwest"  : __DIR__"piaoxue",
        ]));
        setup();
}
