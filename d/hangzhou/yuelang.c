// yuelang.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
������������ǡ��������ա��ĸ����֡����������������
������������������š����Һ�ɽ�������ߵ���ͨ�����أ�������
��ȥ��·��
LONG);
        set("exits", ([
            "north"     : __DIR__"yuefen",
            "south"     : __DIR__"road6",
        ]));
        set("objects" , ([
            "/d/mingjiao/npc/chengchaofeng" : 1,
            __DIR__"npc/honghua2" :2,
        ]));
//        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
