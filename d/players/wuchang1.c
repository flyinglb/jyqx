inherit ROOM;

void create()
{
        set("short", "练武场");
	set("long", @LONG
这里是皇宫内部的一个秘密的监狱，却有数个制作精巧的铜人耸立其间。除
了可以练功外，这里还准备有食物和饮水，同时还可以休息。这是监狱还是练武
场呢？
LONG );
	set("sleep_room",1);
	set("objects", ([
		"/d/baituo/npc/tong-ren" : 5,
		"/clone/food/jitui" : 5,
		"/clone/food/jiudai" : 2,
		"/clone/weapon/zhujian" : 1,
		"/clone/weapon/gangdao" : 1,
		"/clone/weapon/changbian" : 1,
		"/clone/weapon/gangzhang" : 1,
		"/clone/weapon/qimeigun" : 1,
		"/clone/weapon/gangjia": 1,
	]));
        setup();
//	replace_program(ROOM);
}
void init()
{
	add_action("do_ketou", "ketou");
	add_action("do_zisha", "zisha");
}
int do_ketou(string arg)
{
	object me;
	if (!arg ||arg !="yuzu") return 1;
	me = this_player();
	message_vision("$N向外走去。\n",me);
	me->move("/d/dali/shilin");
	message_vision("$N走了过来。\n",me);
	return 1;
}
