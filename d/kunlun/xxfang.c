//Robin 2000.5.15

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","���᷿");
	set("long", @LONG
����ѻ��˺ܶ������ֻ�ƾɵ�ľ�������ﻮ��һ���������˵�·����
���Ӻ��滹��һ���ţ�����ͨ��һ�������Ժ�ӡ�
LONG );
	set("exits", ([
		"east"  : __DIR__"beiyuan",
		"west"  : __DIR__"laying",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

