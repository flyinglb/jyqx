// Room: /d/shaolin/zoulang7.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�������������ȡ������ϲ�ķ�����������ĸ�ǽ����һ��
���뱱�ߺ���Ժ���ݶ�����������ǽ�Ϲ���һ���������������
��Դ�����������޳ִ������������ͨ�����Ժ��
LONG );
	set("exits", ([
		"east" : __DIR__"zoulang8",
		"west" : __DIR__"fzlou",
		"north" : __DIR__"hsyuan1",
		"south" : __DIR__"wuchang2",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

