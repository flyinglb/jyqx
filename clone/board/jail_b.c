// /clone/board/jail_b.c
#include <ansi.h>;
inherit BULLETIN_BOARD;

void create()
{
	set_name(HIG"�ҵ��Թ�״"NOR, ({ "board" }) );
	set("location", "/d/city2/jail");
	set("board_id", "jail_b");
	set("long", HIB"�Ҳ����ˣ������������ҶԲ��������ҵĸ�ĸ��! \n"NOR );
	setup();
	set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}

