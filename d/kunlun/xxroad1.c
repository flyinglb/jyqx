//Robin 2000.5.10

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","С·");
	set("long", @LONG
����С·ͨ��ɽ����Զ����Ҳ������һ����ȵ����գ�ֻ��·������ȴ��
���ߺ��ͣ�·��������һЩ���ҵĲ�ľ��
LONG );
	set("exits", ([
		"south" :  __DIR__"shanlu9",
		"north" :  __DIR__"xxroad2",
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	setup();
	replace_program(ROOM);
}

