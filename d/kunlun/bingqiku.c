//Robin 2000.5.9

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","������");
	set("long", @LONG
�������Խ�����ǽ�ǣ���һ�������ܣ�������ż�����ϰ�õ��񽣡�
LONG );
	set("exits", ([
		"west" :  __DIR__"shijian",
	]));
	set("objects", ([
                "/clone/weapon/zhujian" : 4,
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

