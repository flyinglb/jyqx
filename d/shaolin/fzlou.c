// Room: /d/shaolin/fzlou.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "����¥");
	set("long", @LONG
����ĵ�������������ŷ�����ʮ���Ʋ����ţ�������һ��
��ľ��̳����̳�Ϸ��Ÿ����Ƶ�ľ�㡣�����߸�����һ��������
ۼ�Ĵ�ƿ���ϲ�̴����֦���������ƣ��뵷ҷ�������һƬ��
��֮�������������Ƿ��ɶ�ɮ�ڽ���˵���ĵط���
LONG );
	set("exits", ([
		"south" : __DIR__"wuchang",
		"up" : __DIR__"fzlou1",
		"north" : __DIR__"wuchang3",
		"east" : __DIR__"zoulang7",
		"west" : __DIR__"zoulang6",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

