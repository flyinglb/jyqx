#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
�����ʳָ������������������û��ʲô��
�裬ֻ�м������ź�ľ�˹������ʹ���֮�á�
LONG);
        set("exits", ([
                "west" : __DIR__"dating1",
                "north" : __DIR__"sleep2",
        ]));

        set("objects", ([
                __DIR__"npc/mu-ren" : 5,
        ]));

        setup();
        replace_program(ROOM);
}
