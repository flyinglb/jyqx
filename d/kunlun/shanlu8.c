//Robin 2000.5.9

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","����ɽ·");
	set("long", @LONG
ת��һ��ɽͷ������ɽ��ɽ�������˱仯��ɽԽ��Խ�ߣ������Ǹ�ɽ����
��ɽͷ��ɽ�ϵ���ľҲ���ˣ������µ�����·�Ѳ�������ɽ��ɽ֮�䣬����
��ɽ�����ˡ�
LONG );
	set("exits", ([
		"east"  : __DIR__"shanlu7",
		"west"  : __DIR__"shanlu9",
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	setup();
	replace_program(ROOM);
}

