// Room: /d/gaibang/undertree.c
// Date: Haa 96/03/22

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "ѩ��С��");
	set("long", @LONG
�����Ǵ�ѩɽѩ���µ�һ���ܶ��������������õģ���������
�������ؤ������ռ�����ͭ�����ȡ�������ͨ��ؤ�������ͨ
����
LONG );
	set("exits", ([
		"out"  : "d/xuedao/hollow",
		"northeast" : __DIR__"xsandao2",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

