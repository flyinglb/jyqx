inherit ROOM;
void create()
{
        set("short", "海妖宫");
        set("long", @LONG
这里是飘雪山庄现任庄主海妖住的地方，
虽然屋子里没什么特殊的布置，但是依
然可以看出，这屋子主人身份的不同寻常。
LONG );
	set("no_steal", "1");
	set("sleep_room", "1");
	set("no_clean_up", 0);
        set("exits", ([
                "east"  : __DIR__"piaoxue3",
        ]));
        setup();
}
