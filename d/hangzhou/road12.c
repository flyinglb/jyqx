// road12.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "��ʯ���");
        set("long", @LONG
�غ�����Ե������������ֹ��ӣ������۴��αȣ���������������
һƬ̫ƽ���־��󡣽ֶ�����һ������Ժ����Ժ�ﲻʱ�������ʵ�Ц����
LONG);
        set("exits", ([
            "north"     : __DIR__"road11",
            "south"     : __DIR__"road13",
            "east"      : __DIR__"shuyuan",
        ]));
        set("objects", ([
            __DIR__"npc/likexiu" : 1,
            __DIR__"npc/qingbing" : 4,
        ]));
        set("outdoors", "hangzhou");
//        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
