// /clone/board/chatroom2_b.c

inherit BULLETIN_BOARD;

void create()
{
        set_name(HIY"��ҹ�˼����"NOR, ({ "board" }) );
        set("location", "/d/city/chaguan2");
        set("board_id", "chatroom2_b");
        set("long", "����һ������ҽ�����̶�¹�������԰档\n" );
	setup();
	set("capacity", 200);
	replace_program(BULLETIN_BOARD);
}

