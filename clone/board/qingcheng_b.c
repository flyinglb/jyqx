// /clone/board/qingcheng_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("��ǵ������԰�", ({ "board" }) );
	set("location", "/d/qingcheng/songfengguan");
	set("board_id", "qingcheng_b");
	set("long", "����һ����������½��������԰塣\n" );
	setup();
	set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}

