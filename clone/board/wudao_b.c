// /clone/board/wudao_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("���䱨����", ({ "board" }) );
	set("location", "/d/city/wudao4");
	set("board_id", "wudao_b");
	set("long", "����һ��ר�����䱨���Ĳ���壬������ˮɱ���⡣\n" );
	setup();
	set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}

