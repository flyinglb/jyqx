// Room: /d/songshan/tieliang.c
// Date: CSWORD 96/03/25

inherit ROOM;

void create()
{
	set("short", "����Ͽ");
	set("long", @LONG
�ɴ���ɽ��ɽ·Խ���տ�������Ͽ�Ҳྡ�ǹ�ʯ���������Ϊ��
����ȣ��첻���ס�����Ͽ�ȣ���Է廷�����ƺ�������������ɽ
·��
LONG );
	set("exits", ([
		"down"    : __DIR__"luyanpubu",
		"northup" : __DIR__"shandao5",
	]));
	set("objects", ([
		__DIR__"npc/lu" : 1,
	]));
//	set("no_clean_up", 0);
	set("outdoors", "songshan");
	setup();
	replace_program(ROOM);
}

