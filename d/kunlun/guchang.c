//Robin 2000.5.15

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","�ȳ�");
	set("long", @LONG
��С·���м���һ�������ԸߵĿ����أ�����һֱ��ѩ�������ڳ����м�
��һ���ܴ�Ĺȶѣ����������˸ߣ��ȶ���Ҳ�����˱�ѩ��������̧ͷ��ȥ��
һ����ֱ��ɽ��ֱ���������������ߴ������������ȳ��Ķ������涼�����
��С·��
LONG );
	set("exits", ([
		"east"  : __DIR__"cunlu3",
		"west"  : __DIR__"cunlu4",
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	setup();
	replace_program(ROOM);
}
