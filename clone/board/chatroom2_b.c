// /clone/board/chatroom2_b.c

inherit BULLETIN_BOARD;

void create()
{
        set_name(HIY"玩家构思交流"NOR, ({ "board" }) );
        set("location", "/d/city/chaguan2");
        set("board_id", "chatroom2_b");
        set("long", "这是一个供玩家交流泥潭新构想的留言版。\n" );
	setup();
	set("capacity", 200);
	replace_program(BULLETIN_BOARD);
}

