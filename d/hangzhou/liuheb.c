// liuheb.c
// Date: Nov.1997 by Java
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
��������������ʮһ�㡣��(window)����Ũױ��Ĩ�����Ӻ�����
������˽ǣ���ש���أ��������ܼ�ճ����Щ��������
LONG);
        set("exits", ([
            "down"  : __DIR__"liuhea",
            "up"    : __DIR__"liuhec",
        ]));
        set("objects", ([
            __DIR__"honghua/lu" :1,
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
            objectp(present("lu feiqing", environment(me))))
            return notify_fail("½��������ɭɭ���۹�ɨ����һ�ۣ�������¥�ݵĽ�����һ���¡�\n");
        return ::valid_leave(me, dir);
}
