// /clone/board/wiz_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("��ʦר�ù����(������Խ�������)", ({ "board" }) );
	set("location", "/d/city/wumiao");
	set("board_id", "wiz2_b");
	set("long", "����һ��ר����ʦ��ͨ������԰壬ͨ��һЩ�����й�����Ϣ��\n" );
	setup();
	set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}

