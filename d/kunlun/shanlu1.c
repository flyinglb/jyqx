//Robin 2000.5.9

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","����ɽ��");
	set("long", @LONG
���ڵ�����������Ϊ������ɽ��ɽ�£���հ����ƺƣ��������ƣ������
����������ɳ������������Ұǧ�����������������ɽΡΡ���������
LONG );
	set("exits", ([
		"westup"  : __DIR__"shanlu4",
		"eastdown" : "/d/mingjiao/shanjiao",
		"north" : __DIR__"shanlu2",
		"south" : __DIR__"shanlu3",
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	setup();
	replace_program(ROOM);
}

