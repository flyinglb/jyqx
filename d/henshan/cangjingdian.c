// Room: /d/henshan/cangjingdian.c
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "�ؾ���");
        set("long", @LONG
�ؾ������������£������̫������ "��ؾ�" �����������ľ
���죬����Ʈ���滨��ݣ����������ɫ������ "�ؾ���֮��" ��
��ɽ���ľ�֮һ��
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "east"   : __DIR__"shanlu14",
           "south"  : __DIR__"shuzhuangtai",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

