// /clone/board/wudang_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("��ң�ɵ������԰�",({"board"}));
	set("location","/d/xiaoyao/qingcaop");
	set("board_id", "xiaoy_b");
	set("long", "���ǹ���ң���������Եİ���.\n");
	setup();
	set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}

