//Robin 2000.5.10

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","�᷿");
	set("long", @LONG
��������ׯ���۾�ס�ķ��ӣ��м���û�µ��������ڶ�Ǯ����������ע��
��ʲô���߽�����
LONG );
	set("exits", ([
		"west"  : __DIR__"nanyuan",
	]));
	set("objects", ([
		__DIR__"npc/jiading" : 3,
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

