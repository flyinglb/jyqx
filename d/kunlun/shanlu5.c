//Robin 2000.5.9

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","����ɽ·");
	set("long", @LONG
�������Ĳ��Ƹ�ɽ��Ʈ�������ɽ���ƣ�ɽ�����겻���Ļ�ѩ�����˷ֲ�
�����ƻ���ѩ��ɽ����֮���������ɽ�����е�ѩ����ɼ�֡�������һ���ܣ�
��ʼ���գ�����ɽһ��ߣ��߲����ʡ����µ���·������ɽ����֮����ٳ����
�����յ�ͨ�����
LONG );
	set("exits", ([
		"westup"  : __DIR__"shanlu6",
		"eastdown"  : __DIR__"shanlu4",
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	setup();
	replace_program(ROOM);
}

