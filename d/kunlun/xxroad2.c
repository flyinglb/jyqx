//Robin 2000.5.10

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","С·");
	set("long", @LONG
·�ƽ���ƽ����·�Ե�ɽ������Щɽ���ݾ���������ɽ�ı��棬ɽ���ϵ�
��ľ��ס����������⣬��С·���Ե���һЩ��ɭ��
LONG );
	set("exits", ([
		"south" :  __DIR__"xxroad1",
		"north" :  __DIR__"xxroad3",
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	setup();
	replace_program(ROOM);
}

