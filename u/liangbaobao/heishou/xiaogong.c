#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
�����СָС���������������û��ʲô��
�裬ֻ�м������ź�ľ�˹������ʹ���֮�á�
LONG);
        set("exits", ([
                "west" : __DIR__"huiyi",
                "east" : __DIR__"sleep5",
        ]));

        set("objects", ([
                __DIR__"npc/mu-ren" : 5,
        ]));

        setup();
        replace_program(ROOM);
}
