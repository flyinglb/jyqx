// Room: /d/suzhou/beidajie2.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
����һ����������ʯ�ֵ������ϱ���ͷ���졣�����Ǳ���
��ͨ����⡣�ϱ��Եúܷ�æ��������һ�������¥����Ϊ
����¥��������һ�����֣�������һ����ֱ�Ĵ�֣�ʮ�ַ�����
LONG );
	set("outdoors", "suzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"east"      : __DIR__"jiudian",
		"west"      : __DIR__"zijinan",
		"north"     : __DIR__"beimen",
		"south"     : __DIR__"beidajie1",
	]));
	setup();
	replace_program(ROOM);
}

