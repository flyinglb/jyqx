// /guanwai/milin1.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һƬï�ܵ����֣����ҵ���������б��ɽ���ϡ�ÿ��������������
����ϸ���ߴ�ʮ���ɡ�����֦��Ҷ�ܣ��������ȫ��ס����������Ե���Щ
�谵����ľ֮�䳤�źܶ��ľ�Ӳݣ�ʹ���ߺܼ��ѣ���˵�˲ξ���������Щ
�Ӳ�֮�С�
LONG );
	set("exits", ([
		"west"    : __DIR__"baihe",
		"eastup"  : __DIR__"milin2",
	]));
	set("no_clean_up", 0);
	set("outdoors", "guanwai");
	setup();
	replace_program(ROOM);
}
