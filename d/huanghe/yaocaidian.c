
// Room: /huanghe/yaocaidian.c
// Java. Sep 21 1998

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "Ƥ��ҩ�ĵ�");
	set("long", @LONG
���ǹ��˳���Ψһ��һ�ҵ��̣�һ̤�����ھͿ��ŵ�һ�ɵ�������
ζ���������Կ����ѷ��ں�Ժ��ɹ�ĸ�ʽƤ�������в���ǧ���������
ǽ�ߣ�����һ�����ľҩ������ʢ���˲�ҩ��
LONG );
	set("exits", ([
		"west" : __DIR__"gulang",
	]));
	set("objects", ([
		__DIR__"npc/huoji" : 1,
	]));
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

