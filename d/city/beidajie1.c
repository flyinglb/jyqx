// Room: /city/beidajie1.c
// YZC 1995/12/04 

inherit ROOM;
void create()
{
	set("short", "北大街");
	set("long", @LONG
你走在一条繁忙的街道上，看着操着南腔北调的人们行色匆匆，许多人
都往南边走去，那里有一个热闹的广场。东边是一家生意兴隆的客栈，来自
各地的人们进进出出，据说也是情人们的幽会地点。西边是一家钱庄，可以
听到叮叮当当的金银声音。
LONG
	);
        set("outdoors", "city");
	set("objects", ([
		CLASS_D("btshan") + "/ouyangke" : 1,
//                 __DIR__"obj/jiao" : 1,
	]));
	set("exits", ([
		"east"  : __DIR__"kedian",
		"south" : __DIR__"guangchang",
		"west"  : __DIR__"qianzhuang",
		"north" : __DIR__"beidajie2",
	]));
//	set("objects", ([
//		CLASS_D("mingjiao") + "/zhangwuji" : 1,
//	]));

	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

