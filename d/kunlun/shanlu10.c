//Robin 2000.5.10

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","����ɽ·");
	set("long", @LONG
������ɽ���·Խ��Խ�ߣ��ߵ�������������ɽ�����ˡ�ԶԶ��ȥ���޾�
���ƺ����ڽ��£����ߴ����в����ƣ���͵صľ�ͷȫȻ�ں�����һ����
����Ҳ���ˡ��ڽ����ƺ��Ŀ�϶�俴���ߣ��������������絶����ĸ�ɽ����
����·�ǽ��͵ģ�Զ�����Կ���ɽ��ɽ֮����ɳ�ĸ�ڡ�
LONG );
	set("exits", ([
//		"northwest"  : "/map/mingjiao/gebi1",
		"southwest"  : __DIR__"songlin1",
		"southeast"  : __DIR__"shanlu9",
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	setup();
	replace_program(ROOM);
}

