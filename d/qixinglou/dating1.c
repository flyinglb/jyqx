#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
    set("short","大厅");
    set("long",@LONG
 这里就是七星楼的总堂,是七星楼会客的地方，既不供三清，
 也不供三宝，只供着天地!!!
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
