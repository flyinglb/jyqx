// Room: /d/gaibang/underhs.c
// Date: Haa 96/03/22

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
���ǻ�ɽ�������µ�Сɽ���������������õģ������˸�����
�����ؤ������ռ�����ͭ�����ȡ�������ͨ��ؤ�������ͨ����
LONG );
	set("exits", ([
		"out"       : "/d/huashan/sheshen",
		"southeast" :__DIR__"hsandao2",
	]));
	set("objects" , ([
		CLASS_D("gaibang") + "/li-futou" : 1,
	]));
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
