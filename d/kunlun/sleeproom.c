//Robin 2000

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","����");
	set("long", @LONG
�������ص�����Ϣ˯���ĵط������˼��Ŵ��⣬ֻ�м�����ľ���ļҾߡ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"east" : __DIR__"xiaoyuan2",
	]));
	set("sleep_room", 1);
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
