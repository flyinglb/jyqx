// /clone/board/piaoxue_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("Ʈѩɽׯ���԰�", ({ "board" }) );
	set("location", "/d/piaoxue/dating");
	set("board_id", "piaoxue_b");
	set("long", "����Ʈѩɽׯ�����԰塣\n" );
	setup();
	set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}


