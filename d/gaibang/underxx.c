// Room: /d/gaibang/undertree.c
// Date: Haa 96/03/22

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "ɳ��С��");
	set("long", @LONG
������ɳ��ʯ���µ�һ���ܶ��������������õģ������˸���
�������ؤ������ռ�����ͭ�����ȡ�������ͨ��ؤ�������ͨ
����
LONG );
	set("exits", ([
		"west" : "d/xingxiu/silk4",
		"east" : __DIR__"xxandao2",
	]));
        set("objects",([
                CLASS_D("gaibang") + "/yu-hx" : 1,
        ]));
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

