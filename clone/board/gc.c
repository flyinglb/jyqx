 // /clone/board/gc.c
#include <mudlib.h>

inherit BULLETIN_BOARD;

void create()
{
	set_name(HIC+CHINESE_MUD_NAME+"�����"NOR, ({ "board" }) );
	set("location", "/d/city/guangchang");
	set("board_id", "gc");
	set("long", "��ʦ�ǻ����������һЩ������Ϸ�����±䶯��\n" );
	setup();
	set("wiz_only",1);
	set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}

