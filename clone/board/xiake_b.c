// /clone/board/xiake_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("���͵����԰�", ({ "board" }) );
	set("location", "/d/xiakedao/dating");
	set("board_id", "xiake_b");
	set("long", "����һ�����������͵��Ĺ�����������԰塣\n" );
	setup();
	set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}

