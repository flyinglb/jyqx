// Room: /d/henshan/shanlu8.c
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "ɽ·");
        set("long", @LONG
�����ں�ɽɽ·�ϣ�����ɽ����䣬�������ϪȪ���٣�������
�ƣ��������ش�졣�ϱ߾��Ǹ����¡�
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "southup"  : __DIR__"fuyansi",
           "northup"  : __DIR__"mojingtai",
        ]));
        set("outdoors", "henshan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

