// Room: /city/dongxiang.c
// YZC 1995/12/04 

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
����һ���谵�ķ��䣬�����������������Ϸ���Ƥ�ޡ�ľ�����̾ߣ���Ȼ
���ǲ���˽�����ã���ĥ���ˡ�Ѿ�ߵ����ڡ�һ��Ѿ�߱����Ӱ��ţ��������
���ڵ��Ͽ޿����䣬������һ�������˿ڡ�
LONG );
	set("exits", ([
		"west" : __DIR__"houyuan",
	]));
	set("objects", ([
		__DIR__"npc/hongniang" : 1,
	]));
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

