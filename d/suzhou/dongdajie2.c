// Room: /d/suzhou/dongdajie2.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
�����ڶ�����ϣ����ż�ʵ����ʯ����档�����Ƕ����ţ�
���������سǹٱ���ߺ������������һ�����ֺŵ�ҩ�̣��ϱ�
�Ǵ����̣�����������������Զ����������
LONG );
	set("outdoors", "suzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"east"      : __DIR__"dongmen",
		"north"     : __DIR__"yaopu",
		"south"     : __DIR__"datiepu",
		"west"      : __DIR__"dongdajie1",
		"northwest" : __DIR__"hutong3",
	]));
	setup();
	replace_program(ROOM);
}

