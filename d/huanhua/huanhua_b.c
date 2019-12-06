// /clone/board/huanhua_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("浣花剑庐留言板",({"board"}));
	set("location","/d/huanhua/damen");
	set("board_id", "huanhua_b");
	set("long", "这是供浣花剑庐的弟子们留言的板子.\n");
	setup();
	set("capacity", 30);
	replace_program(BULLETIN_BOARD);
}

