// yuquan.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "��Ȫ");
        set("long", @LONG
��Ȫ�½�����Ȫɽ�ϣ�ԭ�������¡��߽���Ȫ�£�ֻ�������м���ˮ��(pond)��
�������ǳ�����ɽ��·��
LONG);
        set("exits", ([
            "eastdown"  : __DIR__"road5",
        ]));
        set("item_desc", ([
            "pond":
"���Ե�ʯ�����š�������Ȫ��������ż��Сˮ����ӿ������һ������\n",
        ]));
        set("objects" , ([
            __DIR__"npc/you-ke" :1,
        ]));
        set("outdoors", "hangzhou");
//        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
