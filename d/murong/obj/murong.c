// /clone/board/baituo_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("慕容弟子留言板", ({ "board" }) );
	set("location", "/d/mr/yanziwu");
	set("board_id", "murong_b");
	set("long", "这是一个供慕容弟子交流的留言板。\n" );
	setup();
	set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}

