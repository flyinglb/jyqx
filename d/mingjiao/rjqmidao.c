//RJQMIDAO.C

inherit ROOM;

void create()
{
	set("short", "�ܵ�");
	set("long", @LONG
������һ���ص��ľ�ͷ��ʯǽ֮��Ƕ����յ�͵ƣ�����ٿ����
��ǰ��ȥ���ڰ��в�֪������
LONG );
	set("exits", ([
		"north" : __DIR__"rjqjiguan",
//		"down" : __DIR__"rjqmenlou1",
	]));
	set("no_clean_up", 0);
//	set("outdoors", "mingjiao");
	setup();
	replace_program(ROOM);
}

