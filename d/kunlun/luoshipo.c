//Robin 2000.5.10

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","��ʯ��");
	set("long", @LONG
������������Կ��������ϸС�Ŀ϶������ߵ�ɽ·�⣬������һ����
����Ե���ϵ�·����˵���˴�������ȥ�����ɵ�����֥������������˵������
ͨ��һ�����˶�ħ�Ķ��ߡ�
LONG );
	set("exits", ([
		"south" :  __DIR__"xxroad3",
		"eastdown"  :  __DIR__"houshan4",
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	setup();
	replace_program(ROOM);
}

