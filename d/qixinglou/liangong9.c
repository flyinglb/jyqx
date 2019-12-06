// liangong.c

inherit ROOM;

void create()
{
        set("short", "练武场");
	set("long", @LONG
这里是新月格格没事做了练功玩用的地方，旁边立着一个兵器架，各种神兵利器都有。
LONG );
        set("exits", ([ /* sizeof() == 2 */
     "south"     : __DIR__"tangzhu",
     "east"      : __DIR__"restroom9",
     "north"     : __DIR__"water9",
        ]));
     set("objects", ([
            "/d/shaolin/npc/mu-ren" : 5,
        ]));
//   set("no_clean_up", 0);
     set("outdoors", "city" );

     setup();
}
 
