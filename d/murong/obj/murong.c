// /clone/board/baituo_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("Ľ�ݵ������԰�", ({ "board" }) );
	set("location", "/d/mr/yanziwu");
	set("board_id", "murong_b");
	set("long", "����һ����Ľ�ݵ��ӽ��������԰塣\n" );
	setup();
	set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}

