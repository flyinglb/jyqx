// /clone/board/honghua_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("�컨�����԰�", ({ "board" }) );
	set("location", "/d/hangzhou/liuhed");
	set("board_id", "soo_b");
	set("long", "����һ�����컨���ڽ��������԰塣\n" );
	setup();
	set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}

