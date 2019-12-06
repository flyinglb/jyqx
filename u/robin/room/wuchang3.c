inherit ROOM;

void create()
{
        set("short", "山路");
	set("long", @LONG
这里是城市下面的一个秘密的练武场，数个制作精巧的铜人耸立其间。除
了可以练功外，这里还准备有食物和饮水，同时还可以休息。
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
	add_action("do_jump", "jump");
}
int do_jump(string arg)
{
	object me;
	if (!arg ||arg !="up") return 1;
	me = this_player();
	message_vision("$N跳起来落到了储藏室。\n",me);
        me->move("/d/gaibang/chuchang");
	message_vision("$N走了过来。\n",me);
	return 1;
}
