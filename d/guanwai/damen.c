// /guanwai/damen.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���������ע������Ω������ƫ��һ��б�����������裬����Ǵ��š�
��ˮ������������ˮ�����䣬��ʯ�ڼ��ײ������
LONG );
	set("exits", ([
		"southwest"  : __DIR__"longmen",
		"northwest"  : __DIR__"pubu",
	]));
	set("no_clean_up", 0);
	set("outdoors", "guanwai");
	setup();
	replace_program(ROOM);
}
