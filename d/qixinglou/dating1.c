#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
    set("short","����");
    set("long",@LONG
 �����������¥������,������¥��͵ĵط����Ȳ������壬
 Ҳ����������ֻ�������!!!
LONG
    );
    set("exits",([
        "out" : __DIR__"qixinglou",
        "up"  : __DIR__"dating2",
	    ]));
    set("valid_startroom", 1);
    set("no_kill",1);
    set("no_fight",1);
    set("no_hit",1);
    set("steal",1);
    setup();
        "/clone/board/qixing_b"->foo();
}
