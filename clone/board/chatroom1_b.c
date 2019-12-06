// /clone/board/chatroom1_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name(HIG"股票交流ＢＢＳ"NOR, ({ "board" }) );
	set("location", "/d/city/chaguan1");
	set("board_id", "chatroom1_b");
	set("long", "这是一个供玩家交流泥潭之外世界的留言版。\n" );
	setup();
	set("capacity", 200);
	replace_program(BULLETIN_BOARD);
}

