//Robin 2000.5.10

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","ɽ��·");
	set("long", @LONG
���һ��ɽ�壬��ׯ���������ǰ����������·Ҳ̤������ɽ֮�䣬�ʲ�
�������µ�ս�ľ��ĸо���Ȼ��Ȼ�޴棬ȡ����֮��������ǰ�������֮�¡�
��ѩ����֮��Ĵ�ׯ����ׯ��������̫���ˣ����׿�һ·��ƣ���첽������ȥ��
LONG );
	set("exits", ([
		"east"  : __DIR__"jilu2",
		"west"  : __DIR__"zhuwu",
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	setup();
	replace_program(ROOM);
}

