// liuhe4.c
// Date: Nov.1997 by Java
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
���������������Ĳ㡣��(window)����Ũױ��Ĩ�����Ӻ�����
������˽ǣ���ש���أ��������ܼ�ճ����Щ��������
LONG);
        set("exits", ([
            "down"  : __DIR__"liuhe3",
            "up"    : __DIR__"liuhe5",
        ]));
        set("objects", ([
            __DIR__"honghua/shi" :1,
        ]));
        set("item_desc", ([
            "window": "�Ӵ�������ȥ��Ǯ����ȥ������ũ���У���һũ�����ɳ����š�\n",
        ]));
        set("no_clean_up", 0);
        setup();
}
int valid_leave(object me, string dir)
{
        if (dir == "up" &&
            objectp(present("shi shuangying", environment(me))))
            return notify_fail("ʯ˫Ӣ���һ�������ߣ�����ʮ����������͸�����������\n");
        return ::valid_leave(me, dir);
}
