// /clone/board/huashan_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("��ɽ�������԰�", ({ "board" }) );
	set("location", "/d/huashan/buwei3");
	set("board_id", "huashan_b");
	set("long", "����һ������ɽ���½��������԰塣\n" );
	setup();
	set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}

