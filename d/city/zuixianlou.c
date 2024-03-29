// Room: /city/zuixianlou.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "醉仙楼");
	set("long", @LONG
方圆数百里内提起醉仙楼可以说是无人不知，无人不晓。当年苏学士云
游到此，对醉仙楼的花雕酒赞不绝口，欣然为其题匾，流下一段传遍海内的
佳话，从此醉仙楼名声大震。楼下布置简易，顾客多是匆匆的行人，买点包
子、鸡腿、米酒就赶路去了。楼上是雅座。楼梯旁挂着一张告示(gaoshi).
LONG );
	set("exits", ([
		"west" : __DIR__"beidajie2",
                 "up" : __DIR__"zuixianlou2",
                  "north" : __DIR__"xiwan",
         ]));
        set("item_desc", ([
                "gaoshi" : "本店招收打零工人手。有意者请到楼上ask xian about job.\n",
        ]));
	set("objects", ([
		__DIR__"npc/xiaoer2" : 1,
	]));
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

