// /guanwai/huagai.c

inherit ROOM;

void create()
{
	set("short", "���Ƿ�");
	set("long", @LONG
���׶�����߷壬�Թ����������Ƿ���Ƿ�������Ĺʵ��������𴦣�
ǡ���ƿ�����һ�㣬������������ˮ���죬һ����������׳���ģ���������
�塣
LONG );
	set("exits", ([
		"north"     : __DIR__"tianhuo",
		"westdown"  : __DIR__"tianchi1",
	]));
	set("no_clean_up", 0);
	set("outdoors", "guanwai");
	setup();
	replace_program(ROOM);
}
