// Room: /d/henshan/shanlu10.c
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "ɽ·");
        set("long", @LONG
�����ں�ɽɽ·�ϣ�����ɽ����䣬�������ϪȪ���٣�������
�ƣ��������ش�졣ɽ·����ͨ�򷽹��¡������������塣
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "eastup"    : __DIR__"tianzhu",
           "westdown"  : __DIR__"fangguangsi",
        ]));
        set("outdoors", "henshan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

