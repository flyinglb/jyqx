// maojiabu.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "é�Ҳ�");
        set("long", @LONG
·���Ը��ż���С���������ſ�һλ�ϴ�������ι��������С��
����׷����Ϸ���������ϻ����롣�����Ƕ���ɽ��
LONG);
        set("exits", ([
            "southwest"   : __DIR__"tulu1",
            "northup"     : __DIR__"huangniling",
        ]));
        set("objects", ([
            __DIR__"npc/boy" : 1,
            __DIR__"npc/oldwoman" : 1,
            __DIR__"npc/camel" : 1,
        ]));
        set("outdoors", "hangzhou");
//        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
