// by mayue


inherit ROOM;

void create()
{
	set("short", "地窖");
	set("long", @LONG
这是一个阴暗的地窖，头顶被一张草席挡住了光线。地窖里
存放着一些准备过冬的食物，都整齐的堆放在木板上。
LONG
	);
//     set("outdoors", "wudujiao");

	set("exits", ([
//		"out" : __DIR__"minju7",
//		"north" : __DIR__"minju6",
//		"west" : __DIR__"cun1",
//		"north" : __DIR__"wdsl6",
	]));
        set("objects", ([
                __DIR__"obj/shibing": 2,
                __DIR__"obj/huluobu": 1,
                __DIR__"obj/tudou": 1,
	]));
	set("item_desc", ([
		"草席" : "\n一张厚厚的草席盖在洞口，遮住了外面的阳光。\n" ,
	]));
	setup();
//	replace_program(ROOM);
}
void init()
{
        add_action("do_move", "pull");
}
int do_move(string arg)
{
//        object me,hole;
        object me;
        me = this_player();
        if (!arg||arg=="") return 0;
	if( arg=="草席" ) {
//            hole = new(__DIR__"minju10");
		message_vision("\n$N掀开盖在洞口的草席爬了上去。\n", this_player());
             me->move(__DIR__"minju10");
	      message_vision("\n盖在地上的草席忽然一掀，$N从下面钻了出来。\n",me);
	}
	else {
		message_vision("\n$N双手在空中比划了几下，但似乎什么也没抓住。\n", this_player());
	}		
return 1;
}
