// Room: /d/henshan/zhengchuan.c
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
����������������ĵ�������Ժ���������ڵ��ʥ��������
¥�
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "south"  : __DIR__"kuixingge",
           "north"  : __DIR__"yubeiting",
        ]));
        set("outdoors", "henshan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

