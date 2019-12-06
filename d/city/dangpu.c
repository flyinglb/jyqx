// Room: /city/dangpu.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "当铺");
	set("long", @LONG
这是一家以买卖公平著称的当铺，一个五尺高的柜台挡在你的面
前，柜台上摆着一个牌子(paizi)，柜台后坐着唐老板，一双精明的
上上下下打量着你。
   通告：由于原来的当铺系统有一定问题！希望玩家们将原当铺中的
东西取出，当在小宝斋的林月如那里。   谢谢各位合作！
    楼上新开了小宝斋。
LONG
	);
	set("no_fight", 1);
	set("no_beg",1);
        set("no_sleep_room",1);
	set("no_clean_up", 0);
	set("item_desc", ([
		"paizi" : "公平交易\n
sell        卖 
buy         买
redeem      赎人
value       估价
",
	]));
	set("objects", ([
		__DIR__"npc/tang" : 1,
	]));
	set("exits", ([
		"west" : __DIR__"nandajie1",
		"up"   : __DIR__"xiaobaozhai",
	]));

	setup();
	replace_program(ROOM);
}

