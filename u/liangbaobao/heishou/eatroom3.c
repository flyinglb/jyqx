inherit ROOM;

void create()
{
        set("short", "厨房");
	set("long", @LONG
这里是五子山庄的厨房，一个姑娘正在灶边忙来忙去，看来她
就是这里的厨娘了，如果您饿了的话，可以(order)一份吃喝。
LONG );
	set("exits",([
                "east" : __DIR__"dating1",
	]));
	set("no_clean_up", 0);
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
	message_vision("$N刚刚敲完回车，只见空中飞来了一份饭菜送到了$N的面前。\n",me);
		food=new(__DIR__"obj/food");
		water=new(__DIR__"obj/water");
		food->move(me);
		water->move(me);
	return 1; 
}
