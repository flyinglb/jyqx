// /clone/board/taohua_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("����ׯ���°�", ({ "board" }) );
	set("location", "/d/guiyun/qianyuan");
	set("board_id", "guiyun_b");
	set("long", "����һ��ר���һ��������ڵ���ʹ�õ����԰塣\n" );
	setup();
	set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}

