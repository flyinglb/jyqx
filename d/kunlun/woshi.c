//Robin 2000.5.10

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","����");
	set("long", @LONG
������ׯ�����ҵ�ס��������Ĵ����������з�ɫ�軨�Ĵ��������ߵ���
ױ̨ǰ����һλ���Ż���ķ��ˡ�
LONG );
	set("exits", ([
		"north"  : __DIR__"houyuan",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

