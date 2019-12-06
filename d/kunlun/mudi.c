//Robin 2000.5.10

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","墓地");
	set("long", @LONG
林间的一片空地里坐落着十数个坟头，据庄里人讲，这里埋葬的是自段氏
皇族没落以来段氏家臣武姓和朱姓的几代人。绕过这片墓地的前面是一座小小
的祠堂。
LONG );
	set("exits", ([
		"south" : __DIR__"lin4",
		"north" : __DIR__"citang",
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	setup();
	replace_program(ROOM);
}

