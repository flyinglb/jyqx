// Room: /lingzhou/xidajie.c
// Java. Sep 21 1998

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "�����");
	set("long", @LONG
������������֣��ֵ������ɾ�����ש����·�汻��ˮ��ù���
�羵���ֵ�������߷��ߴ����ΰ��˫�˺ϱ�������ʮ��һ�꣬�����
�������ߡ���ֱ���һ�Դ��������������������ԡ��������һƷ��
��̳����������м��ҵ��̣��ֵ��е����塣
LONG );
	set("exits", ([
		"south" : __DIR__"daodian",
		"north" : __DIR__"yipingate",
		"east"  : __DIR__"center",
		"west"  : __DIR__"biaoqiyin",
	]));
	set("no_clean_up", 0);
	set("outdoors", "lingzhou");
	setup();
	replace_program(ROOM);
}

