// Room: /d/quanzhou/dagou.c
// Date: May 7, 96   Jay
#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", "�򹷸�");
	set("long", @LONG
�򹷸�λ��̨���ϲ��������С�������е���������
�ھ�����Ͽ�壬��ǫ̈̄��һ���ۡ�
LONG );
	set("exits", ([
                "north" : __DIR__"chiqian",
	]));
	set("objects", ([
		__DIR__"npc/wokou": 4,
	]));
//	set("no_clean_up", 0);
	set("outdoors", "quanzhou");
	setup();
	replace_program(ROOM);
}

