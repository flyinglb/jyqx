//Robin 2000.5.10

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","卧室");
	set("long", @LONG
这里是庄主武烈的住处，整洁的床上铺着绣有粉色茶花的床单。床边的梳
妆台前坐着一位衣着华贵的夫人。
LONG );
	set("exits", ([
		"north"  : __DIR__"houyuan",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

