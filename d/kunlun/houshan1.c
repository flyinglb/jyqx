//Robin 2000.5.9

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","ɽ·");
	set("long", @LONG
��������������ߵ�·���в�ͬ�羰��ϸ����ɽ·�����ǵͰ���ֻ������
�ߺ��ش����еĹ�ľ��
LONG );
	set("exits", ([
		"northwest"  : __DIR__"houshan2",
		"south" : __DIR__"qipan",
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	setup();
	replace_program(ROOM);
}

