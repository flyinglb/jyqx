// Room: /d/suzhou/dongdajie1.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
�����ڶ�����ϣ����ż�ʵ����ʯ����档�����Ƕ����
�����죬���������ݳ���һ�����ֺŵĵ��̣�������һ��С��
ͬ��
LONG );
	set("outdoors", "suzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"east"      : __DIR__"dongdajie2",
		"north"     : __DIR__"hutong1",
		"south"     : __DIR__"dangpu",
		"southwest" : __DIR__"baodaiqiao",
		"northwest" : __DIR__"canlangting",
	]));
	set("objects", ([
		__DIR__"npc/kid" : 1,
	]));
	setup();
	replace_program(ROOM);
}

