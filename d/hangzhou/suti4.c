// suti4.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "�յ�");
        set("long", @LONG
����������������ϣ�������ɴ��ȸ������һƬ�������յ̴�
������Ϊ����ʮ��֮�ף���Ȼ�����鴫��������ѹ���ţ���������ɽ
�š�����һƬ÷�֣��ֺ��ƺ�����Ժ�䣬���������С�
LONG);
        set("exits", ([
            "north"     : __DIR__"suti3",
            "south"     : __DIR__"suti5",
        ]));
        set("objects", ([
            __DIR__"npc/liyuanzhi" : 1,
            __DIR__"npc/wuya" : 1,
            __DIR__"npc/maque" : 2,
        ]));
//        set("no_clean_up", 0);
        set("outdoors", "hangzhou");
        setup();
        replace_program(ROOM);
}
