// Room: /d/henshan/shanlu2.c
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
           "southeast"  : __DIR__"shanlu1",
           "northup"    : __DIR__"chidifeng",
        ]));
        set("outdoors", "henshan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

