// /clone/board/xueshan_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("ѩɽ�µ������԰�",({ "board" }) );
	set("location", "/d/xueshan/dadian");
	set("board_id", "xueshan_b");
        set("long","���ǹ�ѩɽ�µ��Ӵ�����Ϣ�õ����԰�\n" );
	setup();
	set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}
