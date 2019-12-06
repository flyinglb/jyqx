// liangong6.c

inherit ROOM;

void create()
{
	set("short", "云龙窟");
	set("long", @LONG
这里是人工开挖的一处洞窟，窟中的壁画，结构严密，色彩鲜艳，神态生动，
线条流畅，颇有吴道子一派风格。这里布置的非常简单，仅够满足生活需要。
原来这里是有道高僧修行之处。
LONG
	);
        set("exits", ([ 
		"south" : __DIR__"huayuan2", 		
]));
        set("no_fight",0);
        set("no_steal",0);
        set("sleep_room",1);
	setup();
	replace_program(ROOM);
}
