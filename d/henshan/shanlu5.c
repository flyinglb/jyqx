// Room: /d/henshan/shanlu5.c
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "ɽ·");
        set("long", @LONG
�����ں�ɽɽ·�ϣ�����ɽ����䣬�������ϪȪ���٣�������
�ƣ��������ش�졣�����в�·ͨ��ĥ��̨�������塣����������ܽ��
���ˣ�ף�ڷ�Ҳ�����������
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "southdown"  : __DIR__"banshan",
           "west"       : __DIR__"shanlu6",
           "northwest"  : __DIR__"shanlu13",
        ]));
        set("outdoors", "henshan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

