// Room: /d/shaolin/zoulang8.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�������������ȡ������ϲ�ķ�����������ĸ�ǽ����һ��
��ռ��ڼ���ϸϸ��ʯ���ϣ����������ϣ�������һ��Ƭ���֣�
ܰ����������Ӱҡҷ��ʫ�������ͷ������һ����Ȥ��
LONG );
	set("exits", ([
		"west" : __DIR__"zoulang7",
		"north" : __DIR__"zhulin1",
		"southdown" : __DIR__"luohan9",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

