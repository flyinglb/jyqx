// /clone/board/xueshan_b.c

inherit BULLETIN_BOARD;

void create()
{
        set_name("铁掌帮留言板",({ "board" }) );
        set("location", "/d/tiezhang/guangchang");
        set("board_id", "tiezhang_b");
        set("long","这是供铁掌帮弟子传递信息用的留言板\n" );
	setup();
	set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}
