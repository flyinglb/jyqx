//Robin 2000.5.15

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","���·");
	set("long", @LONG
С·��һ������ɲ���ֺ���һ���Ǹ߲�������ɽ�ͣ�ɽ������·һ��
��������ͨ��Զ������ǰ�棬������һ��Сɽ�壬������������ɽ���ܼ�����
Ӱ�Ѿ��Ǻ��ѵ��ˣ��ο�����һ�����ӡ�
LONG );
	set("exits", ([
		"east"       : __DIR__"guchang",
		"northwest"  : __DIR__"xiaocun",
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	setup();
	replace_program(ROOM);
}

