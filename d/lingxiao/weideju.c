//LUCAS 2000-6-18
// Room: weideju.c

inherit ROOM;
#include <ansi.h> 
void create()
{
        set("short","���¾�");
        set("long",@LONG
���ǰ����ڵ����ң��Ҿ����Σ�����������ν��̻Իͣ���
�������������ڰ������Ѳ�֪ȥ��ֻʣ����һ����ң�������
����ҭҭ�ؿޡ�
LONG);
        set("outdoors", "lingxiao");
        set("exits",([ /* sizeof() == 1 */
            "west"  : __DIR__"book",   
        ]));
        set("objects", ([  
                __DIR__"npc/yaoniang" : 1,
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);

}

