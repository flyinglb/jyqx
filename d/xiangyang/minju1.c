// Room: /d/xiangyang/minju1.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
����һ�ұȽ���Ǯ�˵�ס���������������ڼ���æ��æ�ǣ�
�������������æվ����������к���
LONG );
	set("no_clean_up", 0);

	set("exits", ([
		"west" : __DIR__"jiedao",
	]));
	setup();
	replace_program(ROOM);
}

