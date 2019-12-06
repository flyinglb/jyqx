inherit ROOM;

void create()
{
	set("short", "餐厅");
	set("long", @LONG
这里是给飘雪山庄江湖上的朋友准备的食堂，
如果您饿了的话，可以(order)一份吃喝。
LONG );
	set("exits",([
		"north" : __DIR__"rest2",
	]));
	set("no_clean_up", 0);
	set("count_eat",6);
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
	if (query ("count_eat")>0)
	{
	message_vision("$N刚刚敲完回车，只见空中飞来了一份饭菜送到了$N的面前。\n",me);
		food=new(__DIR__"obj/food");
		water=new(__DIR__"obj/water");
		food->move(me);
		water->move(me);
		add("count_eat",-1);
	}
	else
	message_vision("饭菜已经没了。\n",me);
	return 1; 
}
