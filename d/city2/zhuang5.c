#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", "ׯ������");
    set("long", @LONG
����һ�������ͨ����������.���ߵ�������Ů�����֮����������.
LONG );
    set("exits", ([
		"east" : "/d/city2/zhuang6",
		"west" : "/d/city2/zhuang7",
		"north" : "/d/city2/zhuang8",
		"south" : "/d/city2/zhuang4",
    ]));
    set("objects", ([
		"/d/city2/npc/dizi": 2,
    ]));
    set("outdoors", "city2");
//    set("no_clean_up", 0);
    setup();
    replace_program(ROOM); 
}


