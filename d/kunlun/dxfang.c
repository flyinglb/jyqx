//Robin 2000.5.15

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","���᷿");
	set("long", @LONG
������������˾�ס�ķ��䣬����ʮ���Ű崲ռ�����ⷿ��Ĵ�����ռ䣬
���϶���Щ�ֲ���Ʒ����ȴ����ɾ����ű����˼�ֻ�������Ƶ����衣
LONG );
	set("exits", ([
		"west"  : __DIR__"beiyuan",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

