// yuhuangsj.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "���ɽ��");
        set("long", @LONG
ֻ�����ϵ�ɽ·�������ӡ�ɽ·����һ��С����ͤ������������
��ͤ��Ъ�š���������һ����ʯ�������������ɽ��·��
LONG);
        set("exits", ([
            "northeast" : __DIR__"road15",
            "westup"    : __DIR__"shanlu7",
        ]));
        set("objects", ([
            __DIR__"npc/honghua1" : 2,
        ]));
//        set("no_clean_up", 0);
        set("outdoors", "hangzhou");
        setup();
        replace_program(ROOM);
}
