//Robin 2000.5.9

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","����");
	set("long", @LONG
�ⷿ��ס��������ɰ׳յ��ˣ���˵�������������ڶ�������ɽ��������
��һ�����춯�صĲҰ����������Լ��Ѿ�˵��̫�����ˡ�
LONG );
	set("exits", ([
		"north" :  __DIR__"xiaoyuan1",
	]));
	set("objects", ([
		__DIR__"npc/jiangtao" : 1,
		__DIR__"npc/gaozecheng" : 1,
	]));
	setup();
	replace_program(ROOM);
}

