// Room: /d/xiangyang/hutong1.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "��ͬ");
	set("long", @LONG
���������������ϰ��յľ�ס����ֻ����ͬ��������ЩС
���棬�����С�С�ӻ��̵ȡ�һЩ������������������
LONG );
        set("outdoors", "xiangyang");

	set("exits", ([
		"east" : __DIR__"jiekou1",
	]));
	set("objects", ([
		__DIR__"npc/kid" : 1,
		__DIR__"npc/boy" : 1,
	]));
	setup();
	replace_program(ROOM);
}

