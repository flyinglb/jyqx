// caolianfang.c ������
// Modified by Marz 03/27/96

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
���Ƕ�¥�������ϣ�����˷����Ǵ������䵱������ȥ�Ҵҡ�
LONG );
        set("exits", ([
                "south"     : __DIR__"caolian1",
                "north"     : __DIR__"caolian2",
                "eastdown"  : __DIR__"xilang"
        ]));
//	set("no_clean_up", 0);
        set("objects", ([
                CLASS_D("wudang") + "/yin" : 1
        ]));
        setup();
}
int valid_leave(object me, string dir)
{
    mapping myfam;
    me = this_player();
    myfam = (mapping)me->query("family");
    if ((!myfam || myfam["family_name"] != "�䵱��") && (dir != "eastdown")&&
                objectp(present("yin liting", environment(me))))
           return notify_fail("����ͤŭ�ȵ������㲻���䵱���ӣ��������ڡ�\n");

    return ::valid_leave(me, dir);
}
