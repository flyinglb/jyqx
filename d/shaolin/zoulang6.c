// Room: /d/shaolin/zoulang6.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�������������ȡ������ϲ�ķ�����������ĸ�ǽ����һ��
���뱱�ߺ���Ժ���ݶ�����������ǽ�Ϲ���һ��������������
����������ħ�鱾��Ԫ�񡱡�����ͨ�����Ժ��
LONG );
	set("exits", ([
		"west" : __DIR__"zoulang5",
		"east" : __DIR__"fzlou",
		"north" : __DIR__"hsyuan4",
		"south" : __DIR__"wuchang1",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

