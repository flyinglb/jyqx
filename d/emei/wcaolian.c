
inherit ROOM;

void create()
{
        set("short", "练武场");
        set("long", @LONG
这里是峨嵋派的练武场的西操练房。
正有许多峨嵋派弟子正在此习武练剑。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
               "east" : __DIR__"wuchang",
        ]));

        set("objects", ([
              "/d/shaolin/npc/mu-ren" : 4+random(2)
        ]));

        set("outdoors", "emei" );

        setup();
        replace_program(ROOM);
}
