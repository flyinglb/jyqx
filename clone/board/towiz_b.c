// /clone/board/towiz_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("���������԰�", ({ "board" }) );
	set("location", "/d/wizard/guest_room");
	set("board_id", "towiz_b");
	set("long", "����һ������Һ���ʦ���������԰塣\n" );
	setup();
        set("capacity", 1000);
	replace_program(BULLETIN_BOARD);
}

