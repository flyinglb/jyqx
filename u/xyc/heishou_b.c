// /u/xyc/heishou_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("黑手会会员留言板", ({ "board" }) );
        set("location", "/u/liangbaobao/heishou/dating1");
	set("board_id", "heishou_b.c");
	set("long", "这是一个供黑手会会员交流的留言板。\n" );
	setup();
	set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}
