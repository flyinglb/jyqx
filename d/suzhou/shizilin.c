// Room: /d/suzhou/shizilin.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "ʨ����");
	set("long", @LONG
��һ�߽�ʨ���֣��㲻��Ϊ��������԰�ֵ�������������
����ʨ���ֶ��϶�ɽ��������ˮ�����С���ɽ������֮�ơ���
ɽ���͵��֣�����������ʯ�����಻�ϣ�����Ī�⡣���֮�䣬
���������ɼ���������������Թ������ɵò�Ϊ֮��̾���ѡ�
LONG );
	set("outdoors", "suzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"east"      : __DIR__"yanyutang",
		"west"      : __DIR__"nandajie1",
		"northeast" : __DIR__"zhipoxuan",
	]));
	setup();
	replace_program(ROOM);
}

