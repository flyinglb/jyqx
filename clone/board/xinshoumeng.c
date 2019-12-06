 // /clone/board/gc.c

inherit BULLETIN_BOARD;

void create()
{
            set_name(HIW"新手盟留言版"NOR, ({ "board" }) );
            set("location", "/d/players/xinshoumeng");
           set("board_id", "board");
            set("long", "玩家帮派新手盟成员讨论的地方。\n" );
	setup();
	set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}

