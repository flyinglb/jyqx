
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
����һ����������רΪ���ݴ�����ֱ�ӵ������õġ�
LONG );
	set("exits", ([
		"southwest" : __DIR__"aobai10",
		"northeast" : __DIR__"aobai12",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
