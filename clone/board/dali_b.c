// /clone/board/dali_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("����θ����԰�", ({ "board" }) );
	set("location", "/d/dali/wangfugate");
	set("board_id", "dali_b");
	set("long", "����һ��������θ����½��������԰塣\n" );
	setup();
	set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}

