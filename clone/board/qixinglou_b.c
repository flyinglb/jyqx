// /clone/board/piaoxue_b.c

inherit BULLETIN_BOARD;

void create()
{
        set_name("∆ﬂ–«¬•¡Ù—‘∞Ê", ({ "board" }) );
        set("location", "/d/qixinglou/water7");
        set("board_id", "qixinglou_b");
        set("long", "’‚ «∆ﬂ–«¬•µƒ¡Ù—‘∞Â°£\n" );
	setup();
	set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}


