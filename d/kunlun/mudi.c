//Robin 2000.5.10

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","Ĺ��");
	set("long", @LONG
�ּ��һƬ�յ���������ʮ������ͷ����ׯ���˽���������������Զ���
����û���������ϼҳ����պ����յļ����ˡ��ƹ���ƬĹ�ص�ǰ����һ��СС
�����á�
LONG );
	set("exits", ([
		"south" : __DIR__"lin4",
		"north" : __DIR__"citang",
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	setup();
	replace_program(ROOM);
}

