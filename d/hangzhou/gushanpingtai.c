// gushanpingtai.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "��ɽƽ̨");
        set("long", @LONG
ƽ̨�����С��������¾���ͤ��ͤ��������һ����(duilian)��
���ﻹ������ˮ�أ��ٳ��е�ʯ��ɽ�����õøߵͲβ�������¡�
��������ɽ��·��
LONG);
        set("exits", ([
            "northdown" : __DIR__"gushan",
        ]));
        set("item_desc", ([
            "duilian" :
"ˮ              ��
ɽ              ��
��              ʱ
��              ʱ
��              ��
��              ��\n"
        ]));
        set("outdoors", "hangzhou");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
