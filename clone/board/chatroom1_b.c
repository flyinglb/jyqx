// /clone/board/chatroom1_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name(HIG"��Ʊ�����££�"NOR, ({ "board" }) );
	set("location", "/d/city/chaguan1");
	set("board_id", "chatroom1_b");
	set("long", "����һ������ҽ�����̶֮����������԰档\n" );
	setup();
	set("capacity", 200);
	replace_program(BULLETIN_BOARD);
}

