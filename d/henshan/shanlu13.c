// Room: /d/henshan/shanlu13.c
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "ɽ·");
        set("long", @LONG
�����ں�ɽɽ·�ϣ�����ɽ����䣬�������ϪȪ���٣�������
�ƣ��������ش�졣�����������������ˣ��߸ߴ������������ľ��Ǻ�
ɽ���֮һ��ܽ�ط塣
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "northeast"  : __DIR__"nantian",
           "southeast"  : __DIR__"shanlu5",
        ]));
        set("outdoors", "henshan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

