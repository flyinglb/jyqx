// /clone/board/huanhua_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("佻���®���԰�",({"board"}));
	set("location","/d/huanhua/damen");
	set("board_id", "huanhua_b");
	set("long", "���ǹ�佻���®�ĵ��������Եİ���.\n");
	setup();
	set("capacity", 30);
	replace_program(BULLETIN_BOARD);
}

