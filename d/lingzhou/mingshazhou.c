// Room: /lingzhou/mingshazhou.c
// Java Sep.23 1998

#include <room.h>

inherit ROOM;

void create()
{
	set("short", "��ɳ��");
	set("long", @LONG
��ɳ�޾�����ͭϿ�����Σ��������������ɳ���������ô���
��ڣ�ǿ���������紵�Ļ�ɳ�����ɡ��������죬��ɳ���ɴ˵�����
һ�ߵ�������;���͸���������ɳ�����������������ۣ���������
���۾���
LONG	);
	set("exits", ([
		"northeast" : __DIR__"qingtongxia",
		"southwest" : __DIR__"xuanhebao",
	]));
	set("no_clean_up", 0);
	set("outdoors", "lingzhou");
	setup();
	replace_program(ROOM);
}

