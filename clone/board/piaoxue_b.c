// /clone/board/piaoxue_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("飘雪山庄留言版", ({ "board" }) );
	set("location", "/d/piaoxue/dating");
	set("board_id", "piaoxue_b");
	set("long", "这是飘雪山庄的留言板。\n" );
	setup();
	set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}


