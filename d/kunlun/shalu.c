//Robin 2000.5.15

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","ɳ·");
	set("long", @LONG
���µ�·�ƺ����������������ٿ�����ѩ�ľ�������ȴ���˺ܶ��ɳ��
����һ��ɽ·��ͨ��һ����ʯ���ɳ�ѻ����ɵ�ɽ�塣��ǰ����·Ҳ�����޾�
�ĳ�ɳ�������Ҳ�ڻ����ǳ�ɳ���ˡ�
LONG );
	set("exits", ([
		"southeast"  : __DIR__"shanlin3",
                  "west"  : "/d/gaochang/room63",
//		"northeast"  : "/map/mingjiao/xishan1",
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	setup();
	replace_program(ROOM);
}

