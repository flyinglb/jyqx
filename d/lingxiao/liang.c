//LUCAS 2000-6-18
// Room: liang.c

inherit ROOM;
#include <ansi.h> 
void create()
{
        set("short","����");
        set("long",@LONG
�������Խ��ķ��䣬�����Ե������������������෴������
С����������������ϰ�䣬����ѩɽҲδ�¹�һ��������������
������������У��ǽ����ڰ����ڵġ����ķ���������Ȼ������
һ��һ��������֮�⣬������� 
LONG);
        set("outdoors", "lingxiao");
        set("exits",([ /* sizeof() == 1 */
            "north"  : __DIR__"zoulang3", 
        ]));
        set("objects", ([  
                __DIR__"npc/liang" : 1,
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);

}

