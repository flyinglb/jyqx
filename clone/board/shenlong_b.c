// /clone/board/shenlong_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("�����������԰�", ({ "board" }) );
	set("location", "/d/shenlong/dating");
	set("board_id", "shenlong_b");
	set("long", "����һ�����������µ��ӽ��������԰塣\n" );
	setup();
	set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}
