// Room: /huanghe/weifen.c
// Java. Sep 21 1998

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "μ������");
	set("long", @LONG
�ںӺ�μ�ӻ���ƺӣ���������ˮ�ƣ�Ҳ�����˸������ɳ������
�Ӷ��ǽ����������¡�
LONG );
	set("exits", ([
		"south" : __DIR__"huanghe1",
		"north" : __DIR__"huanghe_1",
		"southwest" : "/d/heimuya/road5",
		"northeast" : "/d/heimuya/dukou2",
	]));
	set("no_clean_up", 0);
	set("outdoors", "huanghe");
	setup();
	replace_program(ROOM);
}

