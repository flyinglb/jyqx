#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
�������ָ������������������û��ʲô��
�裬ֻ�м������ź�ľ�˹������ʹ���֮�á�
LONG);
        set("exits", ([
                "west" : __DIR__"qianyuan",
                "east" : __DIR__"sleep1",
        ]));

        set("objects", ([
                __DIR__"npc/mu-ren" : 5,
        ]));

        setup();
        replace_program(ROOM);
}
