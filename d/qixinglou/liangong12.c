// liangong.c

inherit ROOM;

void create()
{
        set("short", "练武场");
	set("long", @LONG
这里是七星楼弟子的练武场，场上立着几个木人，旁边有吃东西和睡觉的地方。
LONG );
        set("exits", ([ /* sizeof() == 2 */
     "north"     : __DIR__"hufa",
     "south"     : __DIR__"restroom12",
     "east"      : __DIR__"water12",
        ]));
     set("objects", ([
            "/d/shaolin/npc/mu-ren" : 5,
        ]));
//   set("no_clean_up", 0);
     set("outdoors", "city" );

     setup();
}
 
