// cundaota1.c �����һ��
// By Lgg,1998.10

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�����һ��");
        set("long", @LONG
�����Ǵ������һ�㣬������ǵ���ȫ�����������ž���ĵ�
���������ߣ�����һ��һ��Ĵ���ʯ�������ġ����е�����Ҳ������
ʯ��������˵֮������ʯͷ������Ϊ�˱���ʧ���ջ���ȫ��̵ľ�
�顣
LONG
        );
        set("exits", ([
                "south" : __DIR__"guozhendian",
                "westup" : __DIR__"cundaota2",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
