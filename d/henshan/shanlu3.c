// Room: /d/henshan/shanlu3.c
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "ɽ·");
        set("long", @LONG
�����ں�ɽɽ·�ϣ�����ɽ����䣬�������ϪȪ���٣�������
�ƣ��������ش�졣
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "southup"    : __DIR__"chidifeng",
           "northwest"  : __DIR__"shanlu4",
        ]));
        set("outdoors", "henshan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
 
