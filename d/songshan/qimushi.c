// Room: /d/songshan/qimushi.c
// Date: CSWORD 96/03/25

inherit ROOM;

void create()
{
	set("short", "��ĸʯ");
	set("long", @LONG
������һ�����ɾ�ʯ�������ഫ������ˮʱҪ��ͨԯߧɽ������
���ܰ��ڲ�ֹ������Ϳɽ���ͷ�ʱ����ײ�ƣ�ʧ�����ӣ����˻�ʯ��
��ʱͿɽ�������У�����׷�����ӣ���ʯ����һ�ڣ�����������ء�
��ʯ��˻�����ĸʯ��
LONG );
	set("exits", ([
		"southeast" : __DIR__"shandao1",
		"west"      : __DIR__"qimuque",
		"northup"   : __DIR__"shandao2",
	]));
	set("outdoors", "songshan");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

