// Room: zoulang2.c

inherit ROOM;
#include <ansi.h> 
void create()
{
        set("short","����");
        set("long",@LONG 
����һ�����������ȡ����¶����������ӵľ����������ǿ�
����ľ��ң�����ƺ�æ����ͽ�ܡ��ϱ��������ǵ������ң���
���������ܡ������Ǹ�������Ʈ��һ���󷹲˵���ζ��
LONG);
        set("outdoors", "lingxiao");
        set("exits",([ /* sizeof() == 1 */
            "east"  : __DIR__"cook",
            "north"  : __DIR__"roomke",  
            "south"  : __DIR__"roomzhang", 
            "west"  : __DIR__"zhongting",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);

}

