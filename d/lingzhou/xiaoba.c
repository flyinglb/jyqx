// Room: /lingzhou/xiaoba.c
// Java Sep.23 1998

#include <room.h>

inherit ROOM;

void create()
{
	set("short", "С��");
	set("long", @LONG
�����ǻƺӱߵ�һ��С֧����������ƺӻ�ϵĵط������ذ�
��Ϊ�˷�ֹ�ƺӵ���ɳ����������Ӷ�����������һ��СС��ʯ�ӣ�
С�Ӳ��ߣ�������йɳ�Ķ���һ�Ƚ�ʵ��ʯբ�ţ������ǽ�������
����բ�ŵ�������С��ʹ�ô����������İ��������˻ƺ���ɳ����
�š�
LONG	);
	set("exits", ([
		"northeast" : __DIR__"huangyangtan",
		"southwest" : __DIR__"qingtongxia",
	]));
	set("no_clean_up", 0);
	set("outdoors", "lingzhou");
	setup();
	replace_program(ROOM);
}


