// shanlu6.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "ɽ·");
        set("long", @LONG
ɽ·��᫣��������ӡ�������ľ�Դ䣬����ï�ܡ�ɽ·����һɽ
������˵������ʱ�ᴫ���������������ϻ�������������ɽ��·����
����ɽ�㵽��ɽ�ס�
LONG);
        set("exits", ([
            "eastup"  : __DIR__"yuhuangsd",
            "westdown": __DIR__"yuhuangshan",
        ]));
        set("objects", ([
            __DIR__"npc/laohu" : 1,
            __DIR__"obj/shuzhi" : 1,
        ]));
//        set("no_clean_up", 0);
        set("outdoors", "hangzhou");
        setup();
        replace_program(ROOM);
}
