// Room: /d/gaibang/underfz.c
// Date: Haa 96/03/22

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
���Ǹ��ݴ������µ�С���������������õģ������˸��������
��ؤ������ռ�����ͭ�����ȡ�������ͨ��ؤ�������ͨ����
LONG );
	set("exits", ([
		"out"       : "/d/fuzhou/nanmendou",
		"northwest" : __DIR__"fzandao2",
	]));
	set("objects",([
//		CLASS_D("gaibang") + "/li-sh" : 1,
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

