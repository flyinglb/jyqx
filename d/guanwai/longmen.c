// /guanwai/longmen.c

inherit ROOM;

void create()
{
	set("short", "���ŷ�");
	set("long", @LONG
���ŷ��ڳ�鶺���������״�����Σ��������š����¾��ڣ���̬���أ�
����������ˮ����˵������ˮ�����˷壬���������ʯ����
LONG );
	set("exits", ([
		"northeast" : __DIR__"damen",
		"west"      : __DIR__"luming",
		"east"      : __DIR__"tianhuo",
		"southdown" : __DIR__"tianchi1",
	]));
	set("no_clean_up", 0);
	set("outdoors", "guanwai");
	setup();
	replace_program(ROOM);
}
