//Robin 2000.5.9

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","����ɽ·");
	set("long", @LONG
����խխ��ɽ���ϣ�����Ӧ���ǵ�����͵ĵط��ˣ�������һƬ��ľ�͵�
���ɰ���϶��ɵ����֣���������������ȫ���䵽����ɽ·�ϣ���������ɽ
������·�����ѵ�һ���ġ�������һƬ�����ʻ���Ҷ�سɵ�ɽ�꣬����������
�������ɵ����ڡ�
LONG );
	set("exits", ([
		"northdown": __DIR__"sansheng",
		"east"  : __DIR__"shanlu6",
		"west"  : __DIR__"shanlu8",
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	setup();
	replace_program(ROOM);
}

