// /clone/board/player_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("������Թ���԰�", ({ "board" }) );
	set("location", "/d/city/chaguan");
	set("board_id", "player_b");
	set("long", "����һ������ҷ�й������Թ�����԰塣л����������\n" );
	setup();
        set("capacity", 300);
	replace_program(BULLETIN_BOARD);
}

