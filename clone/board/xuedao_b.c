// /clone/board/xuedao_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("Ѫ���ŵ������԰�",({ "board" }) );
	set("location", "/d/xuedao/shandong3");
	set("board_id", "xuedao_b");
        set("long","���ǹ�Ѫ���ŵ��Ӵ�����Ϣ�õ����԰�\n" );
	setup();
	set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}
