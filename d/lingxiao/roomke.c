// Room: roomke.c

inherit ROOM;
#include <ansi.h> 
void create()
{
        set("short","����");
        set("long",@LONG
�����ǿ�����ķ��䡣������ϲ���ռ������������ıڶ���
��������ɫɫ�ĵ����������������󽣣�Ӧ�о��С����߻�����
һ����ֵĶ�������˵��ǰ����������ķ����͸����Ļ�ǹ����
˵��ү����������һ������������ڴ�������һ���¡�
LONG);
        set("outdoors", "lingxiao");
        set("exits",([ /* sizeof() == 1 */
            "south"  : __DIR__"zoulang2", 
        ]));
        set("objects", ([  
                __DIR__"npc/ke" : 1,
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);

}

