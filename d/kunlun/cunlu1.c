//Robin 2000.5.15

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","���·");
	set("long", @LONG
����һ������������ɽ֮���С·�������ǰװ����ĳ�ɽ���룬ɽ������
������������������ж�ߡ�ɽ�����ɡ��ء�ɼ��ϵ�ɽ�֣�����С·����
���������죬����ǰ��Ӧ����ʲô���ڡ�
LONG );
	set("exits", ([
		"east"  : __DIR__"songlin3",
		"northwest"  : __DIR__"cunlu2",
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	setup();
	replace_program(ROOM);
}

