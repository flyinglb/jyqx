// Room: /d/suzhou/zhengdian.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
һ�߽���������㿴�����Ǻų����ݰ˹ֵĻ�����Ƹ��
�溮ɽ��ʰ��д�⻭��ʯ�̺�֣����ָ����ɺ���ʯ������
�ұ����в��������������ɵ���д��ʫ�ģ����������������
����Ʒ���������ҵ�ƫ������δ���ľ���ܵĽ�������޺���
LONG );
	set("no_clean_up", 0);
	set("exits", ([
		"out"   : __DIR__"hanshansi",
		"east"  : __DIR__"hanshidian",
	]));
	setup();
	replace_program(ROOM);
}

