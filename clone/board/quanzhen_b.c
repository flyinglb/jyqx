// /clone/board/quanzhen_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("ȫ���ɵ������԰�", ({ "board" }) );
	set("location", "/d/quanzhen/datang1");
	set("board_id", "quanzhen_b");
	set("long", "����һ����ȫ�������½��������԰塣\n" );
	setup();
	set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}

