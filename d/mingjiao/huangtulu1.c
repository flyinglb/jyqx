// Room: /d/mingjiao/huangtulu1.c
// Date: Java 97/04/9

inherit ROOM;

void create()
{
	set("short", "����С·");
	set("long", @LONG
������ï�������е�һ������С·�����ּ��ܣ����涼��������
�ĸо���ӳ��������ѩ�壬����������
LONG );
	set("exits", ([
		"west" : __DIR__"huangtulu2",
		"east" : __DIR__"shanlu2",
	]));
	set("no_clean_up", 0);
	set("outdoors", "mingjiao");
	setup();
	replace_program(ROOM);
}

