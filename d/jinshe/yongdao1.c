// yongdao1.c
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "��");
        set("long", @LONG
���������˽�ȥ������������һ����խ������������ʵ��ɽ��
�ڵ�һ���ѷ죬����ʮ����Զ�������ߣ���ǰ�����࣬�ѿ�վֱ��
��ͦһͦ������ǰ��ȥ��
LONG );
        set("exits", ([ /* sizeof() == 2 */
            "out"  : __DIR__"shanbi",
            "east" : __DIR__"yongdao2",
        ]));
        set("no_clean_up", 0);
        setup();
	replace_program(ROOM);
}

