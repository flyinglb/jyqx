//LUCAS 2000-6-18
// Room: wave1.c
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short","����");
        set("long",@LONG 
����һ���޴����Ȼ����������Ҳû�뵽������Ȫˮ̶�£�
��Ȼ������һ���������Ķ��츣�ء�վ������·�������ˮ
������һ�㣬����ȫ�Ǿ�Ө��͸�ı��飬����˷������Լ��ĵ�
Ӱ����ɼ�����
LONG);
        set("outdoors", "lingxiao");
        set("exits",([ /* sizeof() == 1 */
            "up"  : __DIR__"water", 
            "west" : __DIR__"wave2", 
        ]));
        if(random(6)>3)
        set("objects", ([
                "/quest/wakuang/kuang/kuangmai" : 1,
        ])); 
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}