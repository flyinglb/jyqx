// /clone/board/songshan_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("��ɽ�������԰�", ({ "board" }) );
	set("location", "/d/songshan/chanyuan");
	set("board_id", "songshan_b");
	set("long", "����һ������ɽ���½��������԰塣\n" );
	setup();
	set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}

