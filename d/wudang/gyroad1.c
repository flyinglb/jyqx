// gytoad1.c ��԰С·
// by Java

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", "��԰С·");
	set("long", @LONG
��ǰ��Ȼ���ʣ������ɵ����ڹ�԰�ߵ�С·�ϡ�·����Ӣ�ͷף���������
���֣�ʢ���ŷۺ���һ�������һƬ���������ߡ������Կ��۷䡸���ˡ�����
������Ϸ���æ����ͣ�������Գ���ߴզ����
LONG );
	set("outdoors", "wudang");

	set("exits", ([
		"west" : __DIR__"tyroad13",
		"east" : __DIR__"gyroad2",
	]));
	set("objects", ([
		__DIR__"npc/snake": 1
	]));
//        set("no_clean_up", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	me = this_player();
	if ( dir == "east" && objectp(present("ju man", environment(me))))
		return notify_fail(RED"��ھ���"NOR"һԾ��ס���ȥ·��\n");

	return ::valid_leave(me, dir);
}
