//TOJMQ1.C

inherit ROOM;

void create()
{
	set("short", "��ʯ���");
	set("long", @LONG
������ͨ����ľ��Ĵ������·��������ſ���ʮ�˲�����С�
���ھ�ľ��������������������࣬���ع������ӵġ������ػ�����
��Χ�����������������з��ݺ�ջ�ŵĽ��졣
LONG );
	set("exits", ([
		"northwest" : __DIR__"tojmq2",
		"southeast" : __DIR__"lhqpaifang",
	]));
	set("no_clean_up", 0);
	set("outdoors", "mingjiao");
	setup();
	replace_program(ROOM);
}
