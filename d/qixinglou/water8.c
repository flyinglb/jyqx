// shantang.c
// shilling 97.2

inherit ROOM;

void create()
{
	set("short", "酒家");
	set("long", @LONG
这里是七星楼弟子吃饭的地方，有好多好吃的哦!都是七星楼的新月格格
为大家特意准备的快叫(order)一份吧。
LONG );
	set("exits",([
		"west" : __DIR__"liangong8",
	]));
	set("no_clean_up", 0);
	set("ricewater", 15);
	setup();
}
void init()
{
        add_action("do_order","order");
}

int do_order(string arg)
{
	object me;
	object food;
	object water;
	me=this_player();
	if (arg)  return notify_fail("萧白蹦出来说道: 给你吃喝，居然要没有的东西，找打。\n");
	if (query("ricewater")>0)
	{
		message_vision("一阵烟雾过后，你身上多了一个香喷喷的烤鸭和一袋好酒，快吃吧$N。\n",me);
		food=new(__DIR__"obj/kaoya");
		water=new(__DIR__"obj/jiudai");
		food->move(me);
		water->move(me);
		add("ricewater",-1);
	}
	else 
		message_vision("萧白蹦出来说道: 嗨，吃的喝的都没了。\n",me);
	return 1; 
}
