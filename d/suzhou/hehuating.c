// Room: /d/suzhou/hehuating.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "�ɻ���");
	set("long", @LONG
�ɻ������������������䣬��ָ�ˬ������ȡ���䣺��һ
ˮ�����̣�ǧ���Ա�족֮ʫ�⡣��ǰ����ƽ̨���ٺɳأ�
Ϊ�����ͺ�����ʤ�����ʳơ��ɻ������������л�̨ͥԺ��
��ʯ�������Գ�һ����
LONG );
	set("outdoors", "suzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"east"  : __DIR__"liuyuan",
		"west"  : __DIR__"gumujiaohe",
	]));
	setup();
	replace_program(ROOM);
}

