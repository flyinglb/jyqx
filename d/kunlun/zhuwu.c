//Robin 2000.5.10

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","��������ׯ");
	set("long", @LONG
һֱ�ߵ���ǰ��ŷ��֣�ԶԶ�����Ĵ�ׯ��ʵ��������ׯ��������������
���ʵ��̫���ˣ��������˸�ǰ��Ҳ��Ҫ��ϸ�ſ������ס�������ׯ��������
����һ��ֻ�н����������������·�Ű���������ׯ���ֿ���������ׯ�ӵ�
ׯ�Ŷ��ڿ�·��Ķ�ͷ��ǰ������������ͯ���ε�����������ׯ�����죬һ��
�ú�����۹�����Զ�����㡣
LONG );
	set("exits", ([
		"east"  : __DIR__"jilu3",
//		"west"  : __DIR__"jilu4",
		"north" : __DIR__"beiyuan",
		"south" : __DIR__"nanyuan",
	]));
	set("objects", ([
		__DIR__"npc/jiading" : 2,
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	setup();
	replace_program(ROOM);
}

