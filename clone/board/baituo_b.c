// /clone/board/baituo_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("����ɽ�������԰�", ({ "board" }) );
	set("location", "/d/baituo/dating");
	set("board_id", "baituo_b");
	set("long", "����һ��������ɽ���ӽ��������԰塣\n" );
	setup();
	set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}
