// Room: /d/suzhou/bailianchi.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������λ�ڶ���ͤ�ı��棬��������ǧҶ���������ϼܲ�
�����ţ��ഫ�����������ʩ���ڴ˲����ͺɡ�
LONG );
	set("outdoors", "suzhou");
//	set("no_clean_up", 0);
	set("exits", ([
		"south" : __DIR__"erxianting",
	]));
	set("objects", ([
		__DIR__"npc/lady2" : 1,
	]));
	setup();
	replace_program(ROOM);
}

