// liufuwest.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
int do_knock(string arg);

void create()
{
        set("short", "�������᷿");
        set("long", @LONG
��������᷿���������øɸɾ���������¶�������̵�֦Ҷ����
����һ����Ⱦ���������źܴ�����ש��һ��ҳ�Ҳ��մ��������С��
�ǲ�֪����������˵��ʲô��
LONG);
        set("exits", ([
            "east"   : __DIR__"liufudating",
        ]));
        set("objects", ([
                __DIR__"npc/liujing" : 1,
                __DIR__"npc/liuqin" : 1,
        ]));
//        set("no_clean_up", 0);
        setup();
	replace_program(ROOM);
}
