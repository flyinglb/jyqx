// Room: zoulang1.c

inherit ROOM;
#include <ansi.h> 
void create()
{
        set("short","����");
        set("long",@LONG 
����һ�����������ȡ����¶����������ӵľ����������ǹ�
�ӵľ��ң���˵��Ŀǰ���ڹ�����ͽ���ϱ���������ķ��䡣��
����һ��������С�䣬��������˯����Ϣ��
LONG);
        set("outdoors", "lingxiao");
        set("exits",([ /* sizeof() == 1 */
            "west"  : __DIR__"sleep",
            "north"  : __DIR__"roomgeng",  
            "south"  : __DIR__"roomwang", 
            "east"  : __DIR__"zhongting",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);

}

