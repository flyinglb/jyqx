// tongtiandian.c ͨ���
// By Lgg,1998.10

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "ͨ���");
        set("long", @LONG
�����ǹ�������֮ĩ--ͨ������Ĵ����ڵ����̲�����ʢ��
��ͨ������Ľ����Աߣ����ż�λ�ؽ̵����󳤶��ɡ������ɡ���
����������
LONG
        );
        set("exits", ([
                "north" : __DIR__"laojundian",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
