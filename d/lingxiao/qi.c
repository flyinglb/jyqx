//LUCAS 2000-6-18
// Room: qi.c

inherit ROOM;
#include <ansi.h> 
void create()
{
        set("short","����");
        set("long",@LONG 
����������ķ��䡣�������Ը���ţ�Ϊ��Ʈ�ݡ�ǽ�Ϲ���
��׵ġ������ơ������������������飬�ּ����ű��ţ��ߵ���
�����ݵ�·�ӣ�������ϡҲ�ܿ��������书�����顣�ձ���һ
����ѩ��ҹ��ͼ������������һҹ�����˰�����̫����ʮկ
�����¡�����ȼ��һ��̴�㣬ɢ�����񾲵���Ϣ��һ�Ž�β�ٰ�
�����ϣ��������������������Ե����֡�
LONG);
        set("outdoors", "lingxiao");
        set("exits",([ /* sizeof() == 1 */
            "north"  : __DIR__"zoulang4", 
        ]));
        set("objects", ([  
                __DIR__"npc/qi" : 1,
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);

}

