// Room: zoulang3.c

inherit ROOM;
#include <ansi.h> 
void create()
{
        set("short","����");
        set("long",@LONG 
����һ�����������ȣ����������߶�����������λ�������
�;�ס�ڴ���Χ�����ϲ�ϲ��ѩ��������Ӵ˴�������˵������
�������а�����Ϊ��ɫ������������ѹ����λ����֮�ơ�����
���в�ϲ���Ѳ��յ��ӡ�
LONG);
        set("outdoors", "lingxiao");
        set("exits",([ /* sizeof() == 1 */
            "north"  : __DIR__"liao",  
            "south"  : __DIR__"liang", 
            "southeast"  : __DIR__"houyuan2", 
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);

}

