//Robin 2000.5.15

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","雅室");
	set("long", @LONG
一桌一椅一床一画，整洁而又秀气，似乎看出房屋的这位闺秀的确有些女
儿家修养，但门边一条细长的带着血腥的皮鞭却破坏了这里整个的气氛。
LONG );
	set("exits", ([
		"west"  : __DIR__"neiyuan1",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

