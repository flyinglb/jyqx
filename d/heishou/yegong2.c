#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
���������ָҶ����������������û��ʲô��
�裬ֻ�м������ź�ľ�˹������ʹ���֮�á�
LONG);
        set("exits", ([
                "east" : __DIR__"huiyi",
                "north" : __DIR__"sleep4",
        ]));

        set("objects", ([
                __DIR__"npc/mu-ren" : 5,
        ]));

        setup();
        replace_program(ROOM);
}
