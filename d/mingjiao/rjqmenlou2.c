//RJQMENLOU2.C

inherit ROOM;

void create()
{
	set("short", "��¥����");
	set("long", @LONG
������һ���ʯ�ң���ʯ�����⿴ȥ������Ժ��һ�����࣬
��������һ�������ѹ��Ľ�Ҫ�ذ���������һ��ʯ��ֱͨ¥�ϡ�
LONG );
	set("exits", ([
		"up" : __DIR__"rjqmenlou3",
		"down" : __DIR__"rjqmenlou1",
	]));
	set("no_clean_up", 0);
//	set("outdoors", "mingjiao");
	setup();
	replace_program(ROOM);
}
