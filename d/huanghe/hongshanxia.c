// Room: /huanghe/hongshanxia.c
// Java Sep. 22 1998

#include <room.h>

inherit ROOM;

void create()
{
	set("short", "��ɽϿ");
	set("long", @LONG
��ɽϿ�Ǹ��ǳ��վ���Ͽ�ȣ���������ʮ�ɵĻ����£����Ƕ��ͣ���
��ֻ��һ������ͨ��һ��һ���խ�����׳ơ�һ���족������û��ʲô��
�ȴ�����ó�������ʧ�١�
LONG );
	set("exits", ([
		"north"     : __DIR__"shimen",
		"south"     : __DIR__"jingyuan",
	]));
	set("objects", ([
		__DIR__"npc/mazei" : 1,
	]));
//	set("no_clean_up", 0);
	set("outdoors", "huanghe");
	setup();
	replace_program(ROOM);
}

