// yongdao2.c
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "��");
        set("long", @LONG
����Ȼת�䣬����������Զ��ǰ���Ȼ����������һ����Ѩ��
��������ʯ�ҡ�
LONG );
        set("exits", ([ /* sizeof() == 2 */
            "north" : __DIR__"shandong",
            "west"  : __DIR__"yongdao1",
        ]));
        set("no_clean_up", 0);
        setup();
	replace_program(ROOM);
}

