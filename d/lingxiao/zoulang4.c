//LUCAS 2000-6-18
// Room: zoulang3.c

inherit ROOM;
#include <ansi.h> 
void create()
{
        set("short","����");
        set("long",@LONG 
����һ�����������ȣ�������������ľ��ң������ǳ���ѧ
�ķ��䡣����������������ͽ���գ��������������һ��������
����ֻ����������ÿ��ǰ����ɨ��
LONG);
        set("outdoors", "lingxiao");
        set("exits",([ /* sizeof() == 1 */
            "north"  : __DIR__"cheng",  
            "south"  : __DIR__"qi", 
            "southwest"  : __DIR__"houyuan2", 
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);

}

