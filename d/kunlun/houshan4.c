//Robin 2000.5.9

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","ɽ·");
	set("long", @LONG
����ȥ��ɽ·�������ѿ�����ɽ���ˣ��������Ƶ���ɼ��������ס��·��
����Ұ����ɽ·Ҳ����һ���ּ�С����
LONG );
	set("exits", ([
		"westup"  : __DIR__"luoshipo",
		"southeast" :  __DIR__"houshan2",
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	setup();
	replace_program(ROOM);
}

