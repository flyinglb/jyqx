
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
		"southwest" :  __DIR__"chaoyang",
		"east" : __FILE__,
		"west" : __FILE__,
		"south" :__FILE__,
		"north" : __DIR__"zhulin2",
	]));
	set("outdoors", "city2");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}



