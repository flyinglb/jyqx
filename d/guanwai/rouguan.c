// /guanwai/rouguan.c

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
����һ���С�Ĺ���ݣ�������һ���ܴ������������ռȥ�˷����һ
�롣������һ������ϼ�һ�ڴ�������������������ӹ��в���ð������
�ݵ��ϰ����ڹ��ԣ����ϵĸ�����ʢ��һ���������ڵ�������
LONG );
	set("exits", ([
		"east"  : __DIR__"nancheng",
	]));
	set("objects", ([
		__DIR__"npc/laoban" : 1,
	]));
//	set("no_clean_up", 0);
//	set("outdoors", "guanwai");
	setup();
	replace_program(ROOM);
}

