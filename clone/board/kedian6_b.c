// /clone/board/kedian6_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("�͵����԰�", ({ "board" }) );
	set("location", "/d/xiangyang/kedian");
	set("board_id", "kedian6_b");
	set("long", "�����õĻ���������˵���ҹ�ˮɱ���⡣\n" );
	setup();
	set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}

