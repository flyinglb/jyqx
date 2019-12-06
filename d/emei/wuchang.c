// Room: /d/emei/wuchang.c

inherit ROOM;

void create()
{
        set("short", "练武场");
        set("long", @LONG
这里是峨嵋派的练武场。练武场上正有许多峨嵋派弟子正在此习武练剑。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"wcaolian",
  "south" : __DIR__"scaolian",
  "north" : __DIR__"hcaguangchang",
 "east" : __DIR__"ecaolian",
]));
        set("no_clean_up", 0);
        set("outdoors", "emei");

        setup();
        replace_program(ROOM);
}
