// Room: /d/henshan/shanlu11.c
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "ɽ·");
        set("long", @LONG
�����ں�ɽɽ·�ϣ�����ɽ����䣬�������ϪȪ���٣�������
�ƣ��������ش�졣������ɽ�ǳ�۷塣����ԶԶ���Կ�����ɽ���֮
һ���ϸǷ��ˡ�
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "westup"  : __DIR__"chidifeng",
           "east"    : __DIR__"shanlu12",
        ]));
        set("outdoors", "henshan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

