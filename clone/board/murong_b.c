// /clone/board/xueshan_b.c

inherit BULLETIN_BOARD;

void create()
{
        set_name("Ľ���������԰�",({ "board" }) );
        set("location", "/d/murong/yanziwu");
        set("board_id", "murong_b");
        set("long","���ǹ�Ľ�����ҵ��Ӵ�����Ϣ�õ����԰�\n" );
	setup();
	set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}
