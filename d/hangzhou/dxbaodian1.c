// dxbaodian1.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "���۱���");
        set("long", @LONG
������������һ���ߴ���ʮ���׵Ĵ�����д�š����۱����
��ǰ�������˽ǾŲ�ʯ���������ֽ��������
LONG);
        set("exits", ([
                "south"     : __DIR__"tianwangdian",
                "enter"     : __DIR__"dxbaodian2",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "hangzhou");
        setup();
        replace_program(ROOM);
}
