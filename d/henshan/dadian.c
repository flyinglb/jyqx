// Room: /d/henshan/dadian.c
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "���");
        set("long", @LONG
�������������������׵�֮�á����ṹΪ����Ъɽ��������
�߲������������ʮ���ߣ������߼䣬��ʯ����ʮ��������������ʮ��
��֮������������ʥ�۱���ׯ�ϡ�������֮��Ϊ��ɽС�ľ�֮һ�� 
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "south"  : __DIR__"yushulou",
           "north"  : __DIR__"houdian",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

