// Room: /d/xiangyang/xiaorong1.c
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
		"west" : __DIR__"jiekou2",
	]));
	set("objects", ([
		__DIR__"npc/kid" : 2,
	]));
	setup();
	replace_program(ROOM);
}

