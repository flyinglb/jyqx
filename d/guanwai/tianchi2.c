// /guanwai/tianchi2.c

inherit ROOM;

void create()
{
	set("short", "��ͷɽ���");
	set("long", @LONG
���ʮ������������ƣ�������˲Ϣ�����������꣬ʹ���ʱ
������������������ʱ���������Ө��ɴ��ʱ����Ծ��󺣲��Σ���ɫ���
����������
LONG );
	set("exits", ([
		"north"    : __DIR__"tianchi1",
	]));
	set("no_clean_up", 0);
	set("outdoors", "guanwai");
	setup();
	replace_program(ROOM);
}
