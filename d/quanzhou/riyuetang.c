// Room: /d/quanzhou/riyuetan.c
// Date: May 7, 96   Jay
#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", "����̶");
	set("long", @LONG
��廷������ˮ�α̵�����̶��̶���������֣�̶��
�������£�Ϊ̨�����ʤ�ء�
LONG );
	set("exits", ([
                "westdown" : __DIR__"chiqian",
	]));
	set("no_clean_up", 0);
	set("outdoors", "quanzhou");
	setup();
	replace_program(ROOM);
}

