// Robin 2000.5.10

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","С·");
	set("long", @LONG
��·������ɽ����ٳ��·�ߵĲ�ľ�����˺ܶ࣬·Ҳ�������ǲ���·�ˣ�
·�Ͼ��Ǵ������Ӳݣ����û�ж���ƽ���ĵط����ܶ�ϸ���ʯͷɢ����·��
���ԡ�����������һ������Ϊ����ʯ�¡���ɽ�¡�
LONG );
	set("exits", ([
		"south" :  __DIR__"xxroad2",
		"north" :  __DIR__"luoshipo",
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	setup();
	replace_program(ROOM);
}

