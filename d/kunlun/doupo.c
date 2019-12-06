//Robin 2000.5.10

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","陡坡");
	set("long", @LONG
这似乎是一条仅有的可以通向那片陡峭山峰的路，路不但陡而且积雪很多，
是那种终年不化坚硬若铁的冰雪。大片的山林已踩在你脚下，远望前方丛山之
中，似乎有一丝炊烟飘起。
LONG );
	set("exits", ([
		"southup"  : __DIR__"pingchuan",
		"northdown"  : __DIR__"songlin3",
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	setup();
}
int valid_leave(object me, string dir)
{
	if (me->query_dex() < 40
	&& dir == "southup")
	{
		message_vision (
"$N往南面是山坡爬去，却一不小心失足摔了下来……\n",me);
		me->add("qi", -30);
		me->add("jing", -30);
		me->unconcious();
		return notify_fail();
	}
	return ::valid_leave(me, dir);
}

