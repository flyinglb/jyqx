// Room: /d/suzhou/beidajie1.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
������һ����æ�Ľֵ��ϣ����Ų�����ǻ������������ɫ
�Ҵң�����˶����ϱ���ȥ��������һ�����ֵ�ͤ�ӡ�������
��һ��Ϸ԰�ӣ���ʱ�����к��������Ը��ص����ǽ���������
�ڶ�����һ���͵ꡣ������һ����ǡ�
LONG );
	set("outdoors", "suzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"east"      : __DIR__"kedian",
		"west"      : __DIR__"majiu",
		"north"     : __DIR__"beidajie2",
		"south"     : __DIR__"canlangting",
		"southwest" : __DIR__"xiyuan",
	]));
	setup();
	replace_program(ROOM);
}

