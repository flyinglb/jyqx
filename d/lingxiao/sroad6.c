// Room: sroad6.c

#include <room.h>
inherit ROOM;
void create()
{
        set("short","ɽ·");
        set("long",@LONG 
�ߵ��������ů��һЩ�ˣ������ڹΣ�������ֻ��������
����ˮ����һ���ײ����ҷ��д��£�����������������һˬ����
���������ڣ�������������Ȼ�Ǹ���Ȫ���ұ����������м���ľ
�ݣ�����������Ѳɽ����ʱס��֮�ء�
LONG);
        set("outdoors", "lingxiao");
        set("exits",([ /* sizeof() == 1 */
            "south"  : __DIR__"sroad5",
            "northup"  : __DIR__"fentianya", 
            "west" : __DIR__"water", 
            "east"  : __DIR__"muwu",
        ]));
        create_door("east", "ľ��", "west", DOOR_CLOSED);
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM); 
}

