// Room: /d/henshan/houdian.c
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "���");
        set("long", @LONG
�������������ĵڰ˽���Ҳ��������۵��޹���
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "south"  : __DIR__"dadian",
           "north"  : __DIR__"beimen",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

