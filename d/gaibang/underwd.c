// Room: /d/gaibang/underwd.c
// Date: Haa 96/03/22

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "�����ѱ�");
	set("long", @LONG
�����䵱ɽ�������ѱ��ϵ�Сɽ���������������õģ������˸���
�������ؤ������ռ�����ͭ�����ȡ�������ͨ��ؤ�������ͨ����
LONG );
	set("exits", ([
		"out"       : "/d/wudang/tufeiwo1",
		"northeast" : __DIR__"wdandao2",
	]));
	set("objects",([
		CLASS_D("gaibang") + "/li-sh" : 1,
	]));
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

