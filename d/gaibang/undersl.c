// Room: /d/gaibang/undersl.c
// Date: Haa 96/03/22

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "�ݽǱ�");
	set("long", @LONG
�������Ǽҳ�����ľ������档�����������õģ������˸�����
�����ؤ������ռ�����ͭ�����ȡ�������ͨ��ؤ�������ͨ����
LONG );
	set("exits", ([
		"up"        : "/d/shaolin/chufang2",
		"southwest" : __DIR__"slandao2",	
	]));
        set("objects",([
                CLASS_D("gaibang") + "/he-bj" : 1,
        ]));
//		CLASS_D("gaibang") + "/he-bj" : 1,
//	]));
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

