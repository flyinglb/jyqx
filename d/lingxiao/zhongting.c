//LUCAS 2000-6-18
// Room: zhongting.c

inherit ROOM;
#include <ansi.h> 
void create()
{
        set("short","��ͥ");
        set("long",@LONG 
�����������ǵ���ͥ�����Ҷ����������ӵ�ס���������ڶ�
�����Ҫ��������������������ƽʱ������ϰ���⣬����֮ʱ��
�����ڷ����ж�����ȭ�ף���������и���� 
LONG);
        set("outdoors", "lingxiao");
        set("exits",([ /* sizeof() == 1 */
            "west"  : __DIR__"zoulang1",
            "north"  : __DIR__"houyuan1",  
            "south"  : __DIR__"qianyuan", 
            "east"  : __DIR__"zoulang2",
        ]));        
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);

}

