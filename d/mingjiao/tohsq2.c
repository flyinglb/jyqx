//TOHSQ2.C

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
������ƺܶ��ͣ�����һ��������ʮ���ɽ�ȣ������ߣ���
��ȥ��������췽���·��·���Է����Ӱ��ɽ����������һ��Ұ
�ط�⡣�������Ǵ����������֮�У������˲������ܵ�һ����
ɪ�ĺ��⡣
LONG );
	set("exits", ([
		"southeast" : __DIR__"tohsq1",
		"northwest" : __DIR__"tohsq3",
		"north"     : __DIR__"tohsq4",
	]));
	set("no_clean_up", 0);
	set("outdoors", "mingjiao");
	setup();
	replace_program(ROOM);
}
