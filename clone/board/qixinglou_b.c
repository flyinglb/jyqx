// /clone/board/piaoxue_b.c

inherit BULLETIN_BOARD;

void create()
{
        set_name("����¥���԰�", ({ "board" }) );
        set("location", "/d/qixinglou/water7");
        set("board_id", "qixinglou_b");
        set("long", "��������¥�����԰塣\n" );
	setup();
	set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}


