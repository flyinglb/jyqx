// Room: /d/gaochang/room75.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
        set("short", "雪谷");
        set("long", @LONG
这里三面是高高耸立的险峰，四周是深可及膝的积雪。
LONG
);

        set("exits", ([ 
  "out" : __DIR__"room63",
]));

        set("objects", ([ 
   __DIR__"obj/xuecan" : 1,
]));

        setup();
        replace_program(ROOM);
}

