// liuhed.c
// Date: Nov.1997 by Java
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
��������������ʮ���㡣��(window)����Ũױ��Ĩ�����Ӻ�����
������˽ǣ���ש���أ��������ܼ�ճ����Щ��������������������
�ߴ���������ȥ���������������۵ס�
LONG);
        set("exits", ([
            "down"  : __DIR__"liuhec",
        ]));
        set("objects", ([
            __DIR__"honghua/chen" :1,
            __DIR__"npc/qianlong" :1,
        ]));
        set("item_desc", ([
            "window": "�Ӵ�������ȥ��Ǯ����ȥ������ũ���У���һũ�����ɳ����š�\n",
        ]));
        set("no_clean_up", 0);
        setup();
	replace_program(ROOM);
	"/clone/board/honghua_b"->foo();

}
