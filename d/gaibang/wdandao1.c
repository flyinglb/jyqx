// Room: /d/gaibang/wdandao1.c
// Date: Haa 96/03/22

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����ؤ�Ｋ�����ܵĵ���ͨ��������ؤ�Ｘ����֮��Ѫ��ɡ� 
LONG );
	set("exits", ([
		"southwest" : __DIR__"wdandao2",
		"northeast" : __DIR__"undertre",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

