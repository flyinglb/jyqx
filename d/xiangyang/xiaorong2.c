// Room: /d/xiangyang/xiaorong2.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "��ͬ");
	set("long", @LONG
���������������ϰ��յľ�ס����ֻ��СŪ��������ЩС
���棬�����С�С�ӻ��̵ȡ�һЩ������������������
LONG );
        set("outdoors", "xiangyang");

	set("exits", ([
		"south" : __DIR__"jiekou2",
	]));
	set("objects", ([
		__DIR__"npc/boy"  : 1,
		__DIR__"npc/girl" : 1,
	]));
	setup();
	replace_program(ROOM);
}

