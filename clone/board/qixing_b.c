// /u/xyc/heishou_b.c
#include <mudlib.h>
inherit BULLETIN_BOARD;

void create()
{
	set_name("七星楼成员留言板", ({ "board" }) );
        set("location", "/d/qixinglou/dating1");
        set("board_id", "qixing_b");

	set("long", "这是一个供七星楼成员交流的留言板。\n" );
	setup();
	set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}
