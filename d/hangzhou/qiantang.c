// qiantang.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "Ǯ������");
        set("long", @LONG
Ǯ������ÿ�����ʮ���ǹ۳��ĺ����ӡ�������ʮ�˳���׳����
���ޡ�����ˮ��ʱ��Զ�������Ὥ�������ģ�����ب��ɽ��������
��������ɲ�Ǽ䣬�������ڣ��������꣬�������ţ������ڣ�����
��������ת�ۣ����Լݳ��硣���������ɽ��˪ѩ�С���׳�����ơ�
��������ɽ�㵽����������
LONG);
        set("exits", ([
            "north"     : __DIR__"road17",
            "westup"    : __DIR__"liuheta",
        ]));
        set("objects", ([
            __DIR__"npc/jian-ke" : 1,
        ]));
        set("outdoors", "hangzhou");
//        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
