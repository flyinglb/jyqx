//Robin 2000.5.15

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","����");
	set("long", @LONG
һ���ܼ�ª�Ĳ��Ҳ��֪����ʲô���������ģ��������ܾ�Ȼ���ò�
ϯΧ���������ڲ������һ��ľ�����ļ��ӣ�����������ݣ������˿���
��������Ϣһ�µġ��������ɽ���İ������������ܣ������Ӻܵ��硣
LONG );
	set("exits", ([
		"south"      : __DIR__"cunlu2",
	]));
	set("no_clean_up", 0);
	set("sleep_room", 1);
	setup();
	replace_program(ROOM);
}

