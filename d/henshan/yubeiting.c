// Room: /d/henshan/yubeiting.c
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "����ͤ");
        set("long", @LONG
����Ϊ�����������ʯ���������ɣ�ʯ���������������ǧ��Ĵ�
ʯ���ϣ�������ϸ�壬��Ϊ������
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "south"  : __DIR__"zhengchuan",
           "north"  : __DIR__"jiayingmen",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

