//Robin 2000.5.10

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","ѩ����ɼ��");
	set("long", @LONG
·������ɽ��ɽ֮���ɼ�������ۣ����м�������һֻ���ӻ����󡣵�
·��ǰ��ȴ������������µ�·���ǻ�ѩ�Ͳݴ����ؿ���С����
LONG );
	set("exits", ([
		"northwest"  : __DIR__"songlin3",
		"east"  : __DIR__"songlin1",
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	setup();
	replace_program(ROOM);
}

