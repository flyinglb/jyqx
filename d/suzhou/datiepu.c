// Room: /d/suzhou/datiepu.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����һ�Ҽ�ª�Ĵ����̣�����һ����¯��¯�������࣬
�������ˡ�һλ���������ͷ�󺹻�����������ר����־����
������ǽ�Ƕ��������깤��δ�깤���������
LONG );
	set("outdoors", "suzhou");
	set("exits", ([
		"north" : __DIR__"dongdajie2",
	]));
        set("objects", ([
		__DIR__"/npc/smith": 1,
	]));
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

