// shiweishi.c ��Ϊ��
// By Lgg,1998.10

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "��Ϊ��");
        set("long", @LONG
������ȫ������֮�����ڵľ��ҡ������С��ֻ�ڷ���һ�Ŵ���
һ��������һ�����ӡ������Ϸ���һ�������ӡ���ֻ����һ�룬����
�����۵����������롣
LONG
        );
        set("exits", ([
                "south" : __DIR__"cetang",
        ]));

        set("objects", ([
                __DIR__"npc/ma" : 1,
        ]));
        setup();
        replace_program(ROOM);
}
