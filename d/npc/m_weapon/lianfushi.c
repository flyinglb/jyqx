//ROOM lianfushi.c
inherit ROOM;

void create()
{
        set("short", "锻斧坡");
        set("long",@LONG
这里是玄兵古洞打造战斧的地方，位处昆仑山西隅一处到处充满
了松树的山林之中。在这个林间的山坡上，一个不是很大的炉窑边，
一个英姿勃发的少年站在那里，看着你走了过来。
LONG	);
        set("exits", ([
                "east" : "/d/gaochang/room63",
        ]));

	set("objects",([__DIR__"npc/shifu" :1,]));

        setup();
	replace_program(ROOM);
}
