// huagang.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "���۹���");
        set("long", @LONG
ֻ��������һС����һ�����ź����档��������Ⱥ����������
Ͷ�������º��㣬��ʳ������л������԰ʱ����ʫһ�ס����Ⱥ����
���࣬����ž��ҷ��㡣��թ������������������˿��˺�����
LONG);
        set("exits", ([
            "east"     : __DIR__"suti6",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "hangzhou");
        setup();
}
