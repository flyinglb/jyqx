// Room: /lingzhou/xiaolu3.c
// Java. Sep 21 1998

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "����С·");
	set("long", @LONG
���Ƕ����ϵ�һ���Ӳݴ�������С·��������ƽʱûʲô�˼���
·�߿��Ų�֪����Ұ�������ߵ�������Ȼ�ߴ�ͦ�Ρ�����͸������
���������ǰ߲߰�����Ӱ�ӡ�
LONG );
	set("exits", ([
		"west"   : __DIR__"biangate",
		"east"   : __DIR__"xiaolu2",
	]));
	set("objects", ([
		"/d/emei/npc/camel" : 1,
	]));
//	set("no_clean_up", 0);
	set("outdoors", "lingzhou");
	setup();
	replace_program(ROOM);
}

