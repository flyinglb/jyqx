//Robin 2000.5.10

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","����ɽ·");
	set("long", @LONG
·��ɽ���ϣ�һ���ǿ��������ĸ�ɽ��һ�����������׵���ȣ���������
��·�ϣ���ʵ�����޷���������ɽ���Ƶķ羰�ˡ���������ɽ֮�䣬����һ��
ͨ�����С·��
LONG );
	set("exits", ([
		"east"  : __DIR__"shanlu8",
		"northwest"  : __DIR__"shanlu10",
		"north" : __DIR__"xxroad1",
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	setup();
	replace_program(ROOM);
}

