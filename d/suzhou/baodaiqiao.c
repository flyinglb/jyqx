// Room: /d/suzhou/baodaiqiao.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����ź�������ݵ��˺�֮�ϣ�����������������������
Ϊ���š���������������������������ű��г����С��ߺ�ȡ�
�����ţ��������������ַǷ������������ڱ̲�֮�ϣ���Ӧ��
�ԣ�����ཿ���������������µ�һ������֮�ء�
LONG );
	set("outdoors", "suzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"northeast" : __DIR__"dongdajie1",
		"northwest" : __DIR__"xidajie1",
		"north"     : __DIR__"canlangting",
		"south"     : __DIR__"nandajie1",
	]));
	set("objects", ([
		__DIR__"npc/seller": 1,
	]));
	setup();
	replace_program(ROOM);
}

