// liuhe1.c
// Date: Nov.1997 by Java
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
�������������ĵײ㡣��(window)����Ũױ��Ĩ�����Ӻ�����
������˽ǣ���ש���أ��������ܼ�ճ����Щ��������
LONG);
        set("exits", ([
            "out"   : __DIR__"liuheta",
            "up"    : __DIR__"liuhe2",
        ]));
        set("objects", ([
            __DIR__"honghua/an" :1,
            __DIR__"honghua/meng" :1,
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
            objectp(present("an jiangang", environment(me))))
            return notify_fail("������һ����ס�㣺Ϲ��ʲô������������ң�\n");
        if (dir == "up" &&
            objectp(present("meng jianxiong", environment(me))))
            return notify_fail("�Ͻ���һ����ס�㣺Ҫ��¥���ȹ�������أ�\n");
        return ::valid_leave(me, dir);
}
