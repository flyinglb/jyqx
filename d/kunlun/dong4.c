//Robin 2000.5.15

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","�ض�");
	set("long", @LONG
һ������ĵض�����ÿ������ж�������ﲢ����խ��ԶԶ������Щ��
������Ծ������ںڵĶ����Ե��ر����ۡ����Կ������ﲢ����ʪ��Ҳû��һ
�����ң��������˾�������ɨ��
LONG );
	set("exits", ([
		"south" : __DIR__"dong3",
		"north" : __DIR__"dong5",
		"west"  : __DIR__"dongshi",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
