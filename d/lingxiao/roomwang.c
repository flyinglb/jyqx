//LUCAS 2000-6-18
// Room: roomwang.c

inherit ROOM;
#include <ansi.h> 
void create()
{
        set("short","����");
        set("long",@LONG 
��������˵��һ�����ң�����˵��һ�������ҡ�����������
��Բ�Ļƶ�����ôҲվ��ס���������˰˸�÷��׮��һ�������
�����������������Ծ��ɣ��������ۻ����ҡ������������ǵ�
�������������������Ṧ׿��������������һ�������������
���ڲ������£�˭Ҳ��֪��������ôѧ�����ģ�Ҳ�����������
������¡�
LONG);
        set("outdoors", "lingxiao");
        set("exits",([ /* sizeof() == 1 */
            "north"  : __DIR__"zoulang1", 
        ]));
        set("objects", ([  
                __DIR__"npc/wang-wanyi" : 1,
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);

}

