// /u/xyc/heishou_b.c
#include <mudlib.h>
inherit BULLETIN_BOARD;

void create()
{
	set_name("����¥��Ա���԰�", ({ "board" }) );
        set("location", "/d/qixinglou/dating1");
        set("board_id", "qixing_b");

	set("long", "����һ��������¥��Ա���������԰塣\n" );
	setup();
	set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}
