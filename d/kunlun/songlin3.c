//Robin 2000.5.10

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","ѩ����ɼ��");
	set("long", @LONG
��ɽ�ּ�Ŀ�϶����Կ��������¾������ֱ�ֱ�������ɽ�ͣ�����ɽɽ
������Զ�����ָ߹������ġ��޾�����ɼ��������޾���ɽ������޷�ȥ��
��ʲô�Ǿ�ͷ��ǰ��·��һֻ���˵�С��������һ��������۹������㣬���
����һ��˵�������ĸо���������ͷ��
LONG );
	set("exits", ([
		"southeast"  : __DIR__"songlin2",
		"southup"  : __DIR__"doupo",
		"west" :  __DIR__"cunlu1",
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	setup();
}
int valid_leave(object me, string dir)
{
	if (me->query_skill("dodge",1) < 40
	&& dir == "southup")
	{
		message_vision (
"$N��������ɽ����ȥ��ȴһ��С��ʧ��ˤ����������\n",me);
		me->add("qi", -20);
		me->add("jing", -20);
		me->unconcious();
		return notify_fail();
	}
	return ::valid_leave(me, dir);
}
//�����ϵ�·�������ϲ�ȥ����ȥ����ׯ������Ҫ��
//�������˵ĺ��Ӻ������������񹷣�
//�书�������30���ᱻ��ҧ�Σ�Ȼ�󱻴�������ׯ��

