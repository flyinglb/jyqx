// Room: /d/gaibang/hsandao1.c
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
		"northwest" : __DIR__"hsandao2",
 		"southeast" : __DIR__"undertre",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

