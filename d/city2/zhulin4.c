
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "����С��");
	set("long", @LONG
���ܶ������ܵ����֣�һ̤�������������·�������˼�������
Ω����̤��ƺ֮����ż����΢�������Ҷ�������������������˳�
��Ϊ֮һ�ӣ����Ǿ��ѵ��������ڡ�
LONG );
	set("exits", ([
		"northeast" : __FILE__,
		"southwest" : __FILE__,
		"east" : __FILE__,
		"west" : __FILE__,
		"south" : __DIR__"zhulin3",
		"north" : __DIR__"zhulin5",
	]));
	set("no_clean_up", 0);
	set("outdoors", "city2");
	setup();
	replace_program(ROOM);
}

