//LUCAS 2000-6-18
// Room: roomgeng.c

inherit ROOM;
#include <ansi.h> 
void create()
{
        set("short","����");
        set("long",@LONG 
����һ�䰲���ľ��ң��������ǵ��������ӹ����ӵķ��䡣
���Ϸ���һ����ѩ�ķ�����ǽ�Ϲ���һ��������������Ӵ�
�������룬����ǽ�ϣ�ӳ��һ�������ｭɽͼ��������ΰ��
LONG);
        set("outdoors", "lingxiao");
        set("exits",([ /* sizeof() == 1 */
            "south"  : __DIR__"zoulang1", 
        ]));
        set("objects", ([  
                __DIR__"npc/geng" : 1,
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);

}

