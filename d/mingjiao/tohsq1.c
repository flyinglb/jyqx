//TOHSQ1.C

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
������һ������ͨ��ɽ·��·�ߵ������ܼ����������㣬�ݴ�
�����ǵ��ص�׺��һЩ��ɫҰ����һ����Ȫ�������˵���ɽ����
�ʣ�Զ����������ˮ����Ϊ��ɽ�ȶ����˼������ơ�
LONG );
	set("exits", ([
		"southeast" : __DIR__"torjq3",
		"northwest" : __DIR__"tohsq2",
	]));
	set("outdoors", "mingjiao");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
