//LUCAS 2000-6-18
// Room: fenghuo.c

inherit ROOM;
#include <ansi.h> 
void create()
{
        set("short","����");
        set("long",@LONG
����������˫��֮һ��������ķ��䡣������Ҳ���������
���ǵ�������ĺۼ�������˭���ⷢй��ŭ���Ƶġ�һ���ֳ�
����������һ�ۣ���ƫ�����ŭɫ���������ӣ�վ�����У�����
���⣬�����ؽ�ҧ,�������޺��¡�
LONG);
        set("outdoors", "lingxiao");
        set("exits",([ /* sizeof() == 1 */
            "west"  : __DIR__"houyuan2", 
        ]));
        set("objects", ([  
                __DIR__"npc/feng" : 1,
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);

}

