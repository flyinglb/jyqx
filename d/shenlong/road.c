#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", "���");
    set("long", @LONG
����һ�����Ĵ����ȫ����ʯ�ѳ�,��Ȼ�����˲�������.
������һƬ������.
LONG );

    set("exits", ([
	"west" : __DIR__"kongdi",
	"north" : __DIR__"road2",
    ]));
    set("objects", ([
	__DIR__"npc/old": 2,
    ]));
    set("outdoors", "shenlong");
    setup();
    replace_program(ROOM); 
}

