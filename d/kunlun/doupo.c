//Robin 2000.5.10

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","����");
	set("long", @LONG
���ƺ���һ�����еĿ���ͨ����Ƭ����ɽ���·��·���������һ�ѩ�ܶ࣬
���������겻����Ӳ�����ı�ѩ����Ƭ��ɽ���Ѳ�������£�Զ��ǰ����ɽ֮
�У��ƺ���һ˿����Ʈ��
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
"$N��������ɽ����ȥ��ȴһ��С��ʧ��ˤ����������\n",me);
		me->add("qi", -30);
		me->add("jing", -30);
		me->unconcious();
		return notify_fail();
	}
	return ::valid_leave(me, dir);
}

