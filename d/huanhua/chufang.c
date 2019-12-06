// chufang.c

inherit ROOM;

void create()
{
	set("short", "妙香斋");
	set("long", @LONG
这里原来是一间不大的厨房，有个厨娘在忙碌着，旁边还有几个仆人在帮忙，
这里专门为人们准备可口的饭菜，你也可以(order)一份。
LONG
	);
	set("exits",([
		"east" : __DIR__"xiaoyuan",
]));
	set("no_clean_up", 0);
        set("count_eat",15);
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
//       if (arg)  return notify_fail("Sorry, 这样东西这里没有啊。\n");
    	if (query ("count_eat")>0)
        {
       message_vision("仆人忙拿来一只烤鸭和一个酒袋给$N\n",me);
	food=new(__DIR__"kaoya");
	water=new(__DIR__"jiudai");
	food->move(me);
	water->move(me);
	add("count_eat",-1);
        }
	else
	message_vision("饭菜已经没了。\n",me);
       return 1; 
}
