// /clone/board/kedian2_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("�͵����԰�", ({ "board" }) );
	set("location", "/d/city2/kedian");
	set("board_id", "kedian2_b");
	set("long", "�����õĻ���������˵���ҹ�ˮɱ���⡣\n" );
	setup();
	set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}

