//LUCAS 2000-6-18
// Room: muwu.c

#include <room.h>

inherit ROOM;
void create()
{
        set("short", "ľ��");
        set("long", @LONG
���������ǵ����ڳ���Ѳ�߻�ɽ��������ÿ�춼��ѩɽ����
�������Ա��������ǰ�ȫ�徻��������ƾ�������������е���ͷ,
һ����С֮��Ҳ�������˵���
LONG );
        set("no_fight", "1");
        set("no_steal", "1");
        set("no_sleep_room", "1");

        set("objects", ([
                __DIR__"npc/wang" : 1,
        ]));

        set("exits", ([
                "west" : __DIR__"sroad6",
        ]));
        create_door("west", "ľ��", "east", DOOR_CLOSED);
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
} 

