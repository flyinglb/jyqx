//LUCAS 2000-6-18
// Room: liao.c

inherit ROOM;
#include <ansi.h> 
void create()
{
        set("short","����");
        set("long",@LONG 
�����������ķ��䡣��λ�����У�������Ϊ���Զ��ǣ�����
˵�����ǵ�����ʦ��ȥʱ���������������ڣ�����������֮ʱ��
����Ѷ�����������֮λ��Ϊ������֮��ⷿ���ڰ������飬
�ӡ����ӱ���������ʷ�ǡ���������Ȩı����֮�顣
LONG);
        set("outdoors", "lingxiao");
        set("exits",([ /* sizeof() == 1 */
            "south"  : __DIR__"zoulang3", 
        ]));
        set("objects", ([  
                __DIR__"npc/liao" : 1,
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);

}

