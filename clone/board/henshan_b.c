// /clone/board/henshan_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("��ɽ�������԰�", ({ "board" }) );
	set("location", "/d/henshan/zhurongdian");
	set("board_id", "henshan_b");
	set("long", "����һ������ɽ���½��������԰塣\n" );
        setup();
        set("capacity", 100);
        replace_program(BULLETIN_BOARD);
}
