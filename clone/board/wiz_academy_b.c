// /clone/board/wiz_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("��ʦ���Բ�", ({ "board" }) );
        set("location", "/d/wizard/academy");
        set("board_id", "wiz_academy_b");
	set("long", "����һ��ר����ʦʹ�õ����԰塣\n" );
	setup();
	set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}

