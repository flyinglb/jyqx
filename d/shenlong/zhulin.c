#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", "����");
    set("long", @LONG
������һƬ������,һ�����紵��,��Ҷɳɳ����,
�����Ǵ���,�����ǽ����ľ���.
LONG );

    set("exits", ([
	"east" : __DIR__"dating",
	"west" : __DIR__"jushi",
    ]));
    set("outdoors", "shenlong");
    setup();
}

