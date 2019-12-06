 // /clone/board/gc.c
#include <mudlib.h>

inherit BULLETIN_BOARD;

void create()
{
	set_name(HIC+CHINESE_MUD_NAME+"公告板"NOR, ({ "board" }) );
	set("location", "/d/city/guangchang");
	set("board_id", "gc");
	set("long", "巫师们会在这儿公布一些关于游戏的最新变动。\n" );
	setup();
	set("wiz_only",1);
	set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}

