//Robin 2000.5.9

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","ɽ·");
	set("long", @LONG
ɽ·���ߵĵͰ���ľ�Ѽ��������ظߴ������е�ѩ����ɼ��������ȥ�ĸ�
ɽ���Ѿ����Լ��������겻���Ļ�ѩ�ˡ�·���и��̶̲�·ͨ��һ��ɽ����
LONG );
	set("exits", ([
		"northwest" : __DIR__"houshan4",
		"southeast" : __DIR__"houshan1",
		"east"  : __DIR__"houshan3",
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	setup();
	replace_program(ROOM);
}

