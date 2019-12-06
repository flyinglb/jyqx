inherit ROOM;
void create()
{
        set("short", "嫣然殿");
        set("long", @LONG
这里是飘雪山庄副庄主纪嫣然的寝殿，纪嫣然是前
任庄主的夫人，这里的布置全是纪嫣然亲手配置的。
LONG );
	set("no_steal", "1");
	set("sleep_room", "1");
	set("no_clean_up", 0);
	        set("exits", ([
                "west"  : __DIR__"piaoxue3",
        ]));
        setup();
}