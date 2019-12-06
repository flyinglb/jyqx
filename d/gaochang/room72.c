// Room: /d/gaochang/room72.c// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
        set("short", "小径");
        set("long", @LONG
道路不知已有多少年无人行走，有些地方长草比人还高，有些地方又全被
沙堆阻塞，四下如死一般的寂静，只有风吹过草梢的沙沙之声。偶尔一两声狼
嚎随着腥风飘至耳际。
LONG
        );
        set("exits", ([ 
  "northwest" : __DIR__"room20",
  "south" : __DIR__"room72",
  "southwest" : __DIR__"room72",
  "northeast" : __DIR__"room72",
  "north" : __DIR__"room72",
  "east" : __DIR__"room72",
  "southeast" : __DIR__"room72",
  "west" : __DIR__"room72",
]));

        setup();
}
