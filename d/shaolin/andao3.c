// Room: /d/shaolin/andao3.c
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
		"up" : __DIR__"zhonglou1",
		"enter" : __DIR__"bagua0",
	]));
	set("no_clean_up", 0);
	setup();
}

int valid_leave(object me, string dir)
{

	if ( dir == "up" )
	{
		if ( me->query_skill("jiuyang-shengong", 1) < 80 )
		{
			return notify_fail("�����������ƶ��ϵ�ש�ǣ����ֱ�������˿������\n" 
			+ "�����ѱ���֭��͸����������һ�㡣������ֻ������취�ˡ�\n");
		}		

		message_vision( HIY
		"$Nȫ�����������������������ٵ�һ��������˫�������ͻ���\n"
		"ֻ��һ�ɰ�����$N���Ķ�����Ѹ���ޱȵػ��ж��ϵ�����ש�ǡ�\n"
		"������һ�����죬ש�Ǳ��������С��Ƭ��ɢƮ�ɡ�¶��һ�����ϵĶ��ڡ�\n" NOR, me );

	}

	return ::valid_leave(me, dir);
}

//��; ��; ��; ��; ��; ��; ��; ��; Ǭ; ��; ��; ��; ��; ��; ��; ��; ��; ��
