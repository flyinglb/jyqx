// /clone/board/emei_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("���ҵ������԰�", ({ "board" }) );
	set("location", "/d/emei/hcaguangchang");
	set("board_id", "emei_b");
	set("long", "����һ�����������½��������԰塣\n" );
	setup();
	set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}

