//TORJQ1.C

inherit ROOM;

void create()
{
	set("short", "��ʯ���");
	set("long", @LONG
������ͨ�������Ĵ������·��������ſ���ʮ�˲�����С�
�ഫ����������������г������磬��ģ��Ϊ��ΰ�ġ��������˲�
�����������ػ�������Χ�����������������б����ͻ��ߵĴ��졣
LONG );
	set("exits", ([
		"northeast" : __DIR__"torjq2",
		"southwest" : __DIR__"lhqpaifang",
	]));
	set("no_clean_up", 0);
	set("outdoors", "mingjiao");
	setup();
	replace_program(ROOM);
}
