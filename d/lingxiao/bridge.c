//LUCAS 2000-6-18
// Room: bridge

inherit ROOM;
#include <ansi.h> 
void create()
{
        set("short","С��");
        set("long",@LONG 
����һ������԰���Ƶ�С�ţ�������Ҷ����岨������ˮ
�����̣������Եá���������ѩ������֮�ˣ�˷�����֮�ƣ���
��ȴ�õ�����ů֮�󣬵���������罭��֮�������������Į
֮�ء�
LONG);
        set("outdoors", "lingxiao");
        set("exits",([ /* sizeof() == 1 */
            "south"  : __DIR__"houyuan2",  
            "north"  : __DIR__"book", 
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);

}

