#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", "С����");
    set("long", @LONG
����һ��С����,���ϵ�������.����ֻ��һ��һ��,
�����,ȴʮ�ָɾ�.�������ű���.
LONG );
    set("exits", ([
		"south" : "/d/city2/zhuang8",
    ]));
    set("objects", ([
		"/d/city2/npc/furen": 1,
		"/d/city2/npc/shuanger": 1,
    ]));
//    set("no_clean_up", 0);
    set("outdoors", "city2");
    setup();
    replace_program(ROOM); 
}


