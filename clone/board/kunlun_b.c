// /clone/board/kunlun_b.c

inherit BULLETIN_BOARD;

void create()
{
        set_name("�����ɵ������԰�", ({ "board" }) );
        set("location", "/d/kunlun/sanshengju");
        set("board_id", "kunlun_b");
        set("long", "����һ���������ɵ��ӽ��������԰塣\n" );
	setup();
	set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}
