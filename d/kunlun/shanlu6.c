// By Robin 2000.3.8

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","����ɽ·");
	set("long", @LONG
Խ��Խ�ߵ�Ⱥɽ֮�������һƬ��ԵͰ���ϡ���ɽ�𣬶��ܼ��纣����
��Ҳϡ������࣬���˿���ֱ������������⡣�����µ�ɽ���ϲ�����ɼ�֣�
����һЩɫ�����޵Ļ��ݣ���������Ұ������ؼ�о�һ���쳣�ľ�ϲ������
������һ��С·ͨ��һ������ǳ�ݰ׻���ɽ��
LONG );
	set("exits", ([
		"northup" : __DIR__"bainiu",
		"west"  : __DIR__"shanlu7",
		"eastdown"  : __DIR__"shanlu5",
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	setup();
	replace_program(ROOM);
}

