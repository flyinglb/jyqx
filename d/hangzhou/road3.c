// road3.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "��ʯ���");
        set("long", @LONG
������߱�ֲ���ɣ���Ŀ�Դ䣬�ȸ���ѩ������Ϊ������ѩ�ɡ���
�������Ǻ鴺�š��������ϱ㵽�������¡��ϱ���һ����·��
LONG);
        set("exits", ([
            "southup"     : __DIR__"huangniling",
            "southwest"   : __DIR__"road2",
            "northeast"   : __DIR__"hongchunqiao",
        ]));
        set("outdoors", "hangzhou");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
