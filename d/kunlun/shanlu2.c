//Robin 2000.5.9

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","����ɽ·");
	set("long", @LONG
���ڵ�����������Ϊ������ɽ��ɽ�£���հ����ƺƣ��������ƣ������
����������ɳ������������Ұǧ�����������������ɽΡΡ���������
LONG );
	set("exits", ([
//              "eastdown" : __DIR__"shilu3",
		"south" : __DIR__"shanlu1",
		"east" :  __FILE__,
		"west" :  __FILE__,
		"north" : __FILE__,
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	setup();
	replace_program(ROOM);
}

