// /clone/board/taohua_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("�һ����������԰�", ({ "board" }) );
	set("location", "/d/taohua/dating");
	set("board_id", "taohua_b");
	set("long", "����һ��ר���һ�������ʹ�õ����԰塣\n" );
	setup();
	set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}

