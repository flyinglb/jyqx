// liuhe8.c
// Date: Nov.1997 by Java
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
�������������İ˲㡣��(window)����Ũױ��Ĩ�����Ӻ�����
������˽ǣ���ש���أ��������ܼ�ճ����Щ��������
LONG);
        set("exits", ([
            "down"  : __DIR__"liuhe7",
            "up"    : __DIR__"liuhe9",
        ]));
        set("objects", ([
            __DIR__"honghua/chang1" :1,
            __DIR__"honghua/chang2" :1,
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
            objectp(present("chang bozhi", environment(me))))
            return notify_fail("����־����ס���ȥ·������һ˿����Ҳû�У�\n");
        if (dir == "up" &&
            objectp(present("chang hezhi", environment(me))))
            return notify_fail("����־Ť��ס������û��һ��Ц�ݣ�\n");
        return ::valid_leave(me, dir);
}
