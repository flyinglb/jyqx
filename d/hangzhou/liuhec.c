// liuhec.c
// Date: Nov.1997 by Java
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
��������������ʮ���㡣��(window)����Ũױ��Ĩ�����Ӻ�����
������˽ǣ���ש���أ��������ܼ�ճ����Щ��������
LONG);
        set("exits", ([
            "down"  : __DIR__"liuheb",
            "up"    : __DIR__"liuhed",
        ]));
        set("objects", ([
            __DIR__"honghua/wuchen" :1,
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
            objectp(present("wuchen daozhang", environment(me))))
            return notify_fail("�޳�����������һ�¾ʹ̵���¥�ݿڡ�\n");
        return ::valid_leave(me, dir);
}
