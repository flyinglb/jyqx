// /clone/board/wudang_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("�䵱�������԰�", ({ "board" }) );
	set("location", "/d/wudang/sanqingdian");
	set("board_id", "wudang_b");
	set("long", "����һ�����䵱���½��������԰塣\n" );
	setup();
	set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}

