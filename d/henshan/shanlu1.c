// Room: /d/henshan/shanlu1.c
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
           "southdown"  : __DIR__"beimen",
           "northwest"  : __DIR__"shanlu2",
        ]));
        set("outdoors", "henshan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

