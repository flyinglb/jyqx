// /clone/board/riyue_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("������̽��ڼ��°�", ({ "board" }) );
	set("location", "/d/heimuya/chengdedian");
	set("board_id", "riyue_b");
	set("long", "����һ��ר��������̽�����ʹ�õ����԰塣\n" );
	setup();
	set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}

