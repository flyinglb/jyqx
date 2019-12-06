// dating.c 
#include <ansi.h>;
inherit ROOM;
string* npcs = ({
	__DIR__"npc/boy",
	__DIR__"npc/boy2",
	__DIR__"npc/boy3",
	__DIR__"npc/boy4",
	__DIR__"npc/girl",
});

void create()
{
	set("short", "�����̴���");
	set("long", @LONG
����һ������,��ǰͻȻ�ֳ�һ������.����˶������,�����ǧ��
֮��.ֻ��һȺȺ������Ů�·���ɫ,��վ�����λ.�ࡢ�ס��ڡ���
��ɫ�Ķ�������,�����ȴ����Ů,���ϸ����̽�,ÿһ��Լ�а���.
LONG );

	set("exits", ([
		"south" : __DIR__"damen",
		"north" : __DIR__"houting",
		"west"  : __DIR__"zhulin",
		"east"  : __DIR__"zoulang",
	]));
	set("valid_startroom","1");

	set("objects", ([
		npcs[random(sizeof(npcs))] : 1,
		npcs[random(sizeof(npcs))] : 1,
		__DIR__"npc/yunsumei": 1,
		CLASS_D("shenlong")+"/hong":  1,
		CLASS_D("shenlong")+"/wugen": 1,
	]));
	setup();
	"/clone/board/shenlong_b"->foo();
//	replace_program(ROOM);
}

 
int valid_leave(object me, string dir)
{
	if (dir != "south" )
	{
		if(me->query("party/party_name") !=HIY "������" NOR)
		{
			if(present("wugen daozhang", environment(me)) && living(present("wugen daozhang", environment(me))))
			{
				return notify_fail(
"�޸������ȵ��������Ǳ����صأ���λ" + RANK_D->query_respect(me) + "��ֹ����\n");
			}
			else
				return ::valid_leave(me, dir);
		}
		else
			return ::valid_leave(me, dir);
	}
	else
		return ::valid_leave(me, dir);

}
