 // /clone/board/gc.c

inherit BULLETIN_BOARD;

void create()
{
            set_name(HIW"���������԰�"NOR, ({ "board" }) );
            set("location", "/d/players/xinshoumeng");
           set("board_id", "board");
            set("long", "��Ұ��������˳�Ա���۵ĵط���\n" );
	setup();
	set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}

