// Room: /d/gaibang/underbj.c
// Date: Haa 96/03/22

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "�ֱ߹���");
	set("long", @LONG
���Ǳ�����һ��ƫƧ�ֱߵĹ�������ܶ����˸������
����ؤ������ռ�����ͭ�����ȡ�������ͨ��ؤ�������ͨ����
LONG );
	set("exits", ([
		"out"   : "/d/city2/aobai1",
		"south" : __DIR__"bjandao2",
	]));
        set("objects",([
                CLASS_D("gaibang") + "/quan-gq" : 1,
        ]));
//		CLASS_D("gaibang") + "/quan-gq" : 1,
//	]));
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

