//Robin 2000.5.10

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","ɽ��ƽ��");
	set("long", @LONG
����һ��ɽ��ɽ֮���ƽ�أ������Ǵ�����ʮ�ɶ����������������Ϣһ
�µĵط���������Զ����Ⱥɽ�����ڰ�ѩ�����֮�䣬���ǽ�׵�����ѩ����
����������̵�ɽ�֡�����ɽ�����֣����ƣ���ѩ����ǰ��һ�־�������Ȼʧ
ɫ�ˣ���Ϊ����һ����ׯ��һ��Ʈ�Ŵ��̵Ĵ�ׯ����һ������ǧ�￴��������
��������˵���Ǵ������ž޴����������
LONG );
	set("exits", ([
		"west"  : __DIR__"jilu1",
		"northdown"  : __DIR__"doupo",
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	setup();
	replace_program(ROOM);
}

