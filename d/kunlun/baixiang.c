//Robin 2000.5.15

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","����ɽ");
	set("long", @LONG
��᫵�ɽ��С·;����������ѩ���ǵ�ɽ�壬̧������������ããһƬ��
������ɽ����ʲô��������ɽ����������������������ˣ���û����ָ��
��Ҫ��ɽ�����ǲ�̫�ð���ˡ�ɽ·�������죬ԶԶ��ȥ������ɽ���ֽ�֯��
���ޡ�
LONG );
	set("exits", ([
		"southeast"  : __DIR__"shanlin2",
		"northwest"  : __DIR__"shanlin3",
//		"eastup" : __DIR__"shanbi",
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	setup();
}
void init()
{
	add_action("do_climb", "climb");
}
int do_climb(string arg)
{
	object me=this_player();
	if (arg != "shan") return 0;
	message_vision(HIW
"$N�ߵ�ɽ���£���ͼ����ɽȥ��\n"NOR,me);
	if ((int)me->query_dex() < 40)
	{
		message_vision(HIR
"$Nһ��ʧ�֣���ɽ����ˤ����������\n"NOR,me);
		me->set("qi",10);
		me->set("jing",10);
		me->unconcious();
		return 1;
	}
	if (!(int)me->query_temp("��֥")) 
	{
	message_vision(HIB "$Nʼ���Ҳ�����������ȥ��·��ֻ���Ȼ���ա�\n"NOR,me);
                return 1;
        }
        message_vision(HIW
"$N���㲢�õ�������һ���ϸߵĵط���\n"NOR,me);
        me->move(__DIR__"shanbi");
	me->delete_temp("��֥");
        return 1;
}
