// Room: /lingzhou/yipindating.c
// Java. Sep 21 1998

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "һƷ�ô���");
	set("long", @LONG
����������һƷ�õĴ��������������Ե��е����ޡ���ʮ���ϱ�
�������ſ����嶥�ķ��ܣ��������պ���ɭɭɷ�ˡ���������һ���ľ
�Ҷ�(bian)�������������ף�������������ľ������Ƥ�����ϣ�����
�����ŵģ����������󽫾������ܹܡ���Χ���ż���һƷ����ʿ���Ʒ�
������
LONG );
	set("item_desc", ([
		"bian"  : "һƷ��\n",
	]));
	set("exits", ([
		"south"  : __DIR__"yipindayuan",
	]));
	set("objects", ([
		"/quest/helian" :1,
		__DIR__"npc/yipinwushi" :4,
	]));
	set("no_fight",1);
	setup();
	replace_program(ROOM);
}

