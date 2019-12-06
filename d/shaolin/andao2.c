// Room: /d/shaolin/andao2.c
// Date: YZC 96/02/06

#include <login.h>
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ��������ʪ�ĵص����ı��ôֲڵ�Ƭ���ݶ���ɣ�һ
�ſ�ˮ������ǽ�ڹ����������ڵ��ϡ�Ҳ������Ϊ��ʱ������ͨ
�е�Ե�ʣ������ص�������һ�ɸ�ʬ��Ķ����
LONG );
	set("exits", ([
		"up" : __DIR__"gulou1",
	]));
	set("no_clean_up", 0);
	setup();
}

void init()
{       
	object ob;

	if( interactive(ob = this_player()) 
	&& (int)ob->query_condition("bonze_jail") >= 0 )
	{
		message("vision",
			HIY "ֻ��ˮ����������һ�죬һ��������ڣ�ȫ���ཬ�ļһ����˹�����\n\n" NOR, 
			environment(ob), ob);

		tell_object(ob, "����û������ɣ������߳�����������Ի����ӳ������ˣ�\n");

		ob->set("startroom", START_ROOM);
		ob->clear_condition("bonze_jail");
	}
}

