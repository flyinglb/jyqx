// Room: /d/henshan/tianzhu.c
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
�����Ϻ�ɽ���֮һ�������壬����Ⱥɽ��������У�ÿÿ������
ʪʱ������������������������ˡ� 
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "westdown"   : __DIR__"shanlu10",
           "eastdown"   : __DIR__"shanlu7",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

