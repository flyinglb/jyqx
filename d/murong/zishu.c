// /u/beyond/mr/sishu.c
// this is made by beyond
// update 1997.7.1
#include <ansi.h>
inherit ROOM;
void create()
{
set("short", "˽��");
	set("long", @LONG
������Ľ�ݼ�������ã�Ϊ���ü���ĺ����ܹ��õ��ܺõĽ�����Ľ��
������Ƹ����һλ˽�����������Ρ�
LONG
	);

	set("exits", ([
		"south" : __DIR__"shufang",
	]));

	set("objects", ([
		__DIR__"npc/xiansheng": 1,
	]));

	setup();
}

int valid_leave(object me, string dir)
{
	me->delete_temp("mark/��", 0);
	return 1;
}


