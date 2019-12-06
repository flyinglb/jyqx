#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
    set("short","水月轩");
    set("long",@LONG
这是七星楼紫薇堂堂主欧阳婉竹休息的地方!整个房间四周帷幔轻纱,在风中轻轻飘动!
左边的白玉瑶琴一看就知道决非凡品!右面墙上斜挂着欧阳的随身利器婉竹!这是她初到江湖
的兵器!先已经久置不用了!
LONG
    );
    set("sleep_room","1");
    set("exits", ([ /* sizeof() == 2 */
	"south" : __DIR__"liangong11",
        "northeast" : __DIR__"chang5",
    ]));
    set("no_fight",1);
    set("no_sleep_room",1);
    set("no_steal",1);
    set("no_beg",1);
    setup();
}
