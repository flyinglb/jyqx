// yuanshidian.c Ԫʼ��
// By Lgg,1998.10

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "Ԫʼ��");
        set("long", @LONG
�����ǹ���Ԫʼ����Ĵ������������ƣ�����������Ԫʼ��
��Ľ����Ա߻����ż�λ������̫�ҡ�����������ӡ�����ӵ�
�ȵ���������һ�����ɻ����������衣
LONG
        );
        set("exits", ([
                "south" : __DIR__"laojundian",
        ]));
        set("objects", ([
                __DIR__"npc/qi" : 1,
        ] ));

        setup();
        replace_program(ROOM);
}
