// Room: /d/henshan/shiziyan.c
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "ʨ����");
        set("long", @LONG
ʨ���Ҳ������ι�״����ʯ��ϸ�������ʨ�ӣ���Ծ���𣬸�Ф��
�ࡣ��ʨ���ң�ף�ڷ��Ѿ������ˡ�
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "southwest"  : __DIR__"nantian",
           "northup"    : __DIR__"wangritai",
        ]));
        set("outdoors", "henshan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

