// Room: /huanghe/huangtu.c
// Java. Sep 21 1998

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "������ԭ");
	set("long", @LONG
�ƺ���һ�����н�������ԭ�п���������СϪ���д�����ɳ�����
�ӣ��γ�ǧ�����֡�����֮���һ���ƽ�ؽ���̨ܫ���ƺ����ɹŸ�ԭ
�ϱ������ʣ���̫��ɽ������������תͷ���£��γɽ��µķֽ硣
LONG );
	set("exits", ([
		"northeast" : __DIR__"hetao",
		"southwest" : __DIR__"huanghe_2",
	]));
	set("no_clean_up", 0);
	set("outdoors", "huanghe");
	setup();
	replace_program(ROOM);
}

