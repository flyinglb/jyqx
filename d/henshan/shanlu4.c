// Room: /d/henshan/shanlu4.c
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "ɽ·");
        set("long", @LONG
�����ں�ɽɽ·�ϣ�����ɽ����䣬�������ϪȪ���٣�������
�ƣ��������ش�졣
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "southeast" : __DIR__"shanlu3",
           "northup"   : __DIR__"banshan",
        ]));
        set("outdoors", "henshan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

