
inherit ROOM;

void create()
{
	set("short", "客店后院");
	set("long", @LONG
这里客店后院。一阵阵打斗之声从东面的厢房 (room) 中传来，
其中夹杂着一个女子的声音。房门的板壁(wall)不住的震动，似乎
客房四周的板壁都要被刀风掌力震坍一般。西首也是厢房，不时有
人探头出来观望。北面是客店大门。
LONG );
        set("no_sleep_room",1);
	set("exits", ([
		"west" : __DIR__"kedian4",
		"east" : __DIR__"kedian3",
		"north" : __DIR__"kedian1",
	]));
	set("item_desc", ([
		"wall" : "\n这是一堵木墙，板壁不过一寸来厚，被震得摇摇晃晃。\n",
	        "room" :
"\n你往房中望去，只见六个喇嘛手持戒刀，围着一白衣女尼拼命砍杀，\n"+
"只是给白衣女尼的袖力掌风逼住了，欺不近身。但那白衣女子头顶已冒\n"+
"出丝丝白气，显然已尽了全力。她只一条臂膀，再支持下去恐怕难以抵敌。\n"+
"地上斑斑点点都是血迹。\n",
	]));
	set("no_clean_up", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	int i;
        if(me->query_temp("hastrystab")==6)
	return ::valid_leave(me, dir);
	if (dir == "east" )
	{
	i = (int)me->query_skill("dodge", 1) + random(1000);
	if(i>600) 
        return notify_fail(
	"\n你一步踏进客房，突觉一股力道奇大的劲风激扑出来，将你一撞，\n"+
	"你登时立足不稳，腾腾腾到退三步，一交坐倒。\n");
        me -> receive_damage ("qi",50) ;
        me -> receive_wound  ("qi",50) ;
	}
	return ::valid_leave(me, dir);
}

void init()
{
add_action("do_thrust","thrust");
add_action("do_thrust","ci");
add_action("do_thrust","stab");
}

int do_thrust(string arg)
{
	object room, me,man;
        me = this_player();
	if( !arg || arg!="wall" ) return notify_fail("你要刺什么？\n");

        if(!present("blade" , me)
         &&!present("bishou" , me)
         &&!present("sword" , me)
         &&!present("gangjian" , me)
         &&!present("changjian" , me)
         &&!present("duanjian" , me))
	return notify_fail("不用刀剑恐怕不行吧！\n");

        if(me->query_temp("hastrystab")<6)
        message_vision( "\n$N走到墙边，抽出兵刃，对准木板狠狠地一戳。\n",me);
        if(!present("bishou" , me))
        message_vision( "结果$N笃的一声，兵刃插入寸许，再也刺不进半分。\n",me);
        else
	{
        if(me->query_temp("hastrystab")<6)
          {
	if(!( room = find_object(__DIR__"kedian3")) )
		room = load_object(__DIR__"kedian3");
	if(objectp(room))
            {
		if(!present("lama",room))
		{
                message_vision( "只听噗的一声，匕首轻轻穿过木板，但隔壁没什么动静。\n",me);
	        message("vision", "忽然一柄匕首从墙外戳了进来。\n",room );
		}
		else
		{
                message_vision( "只听噗的一声，匕首轻轻穿过木板，房中立时传来一声惨叫。\n",me);
                me->add_temp("hastrystab",1);
		message("vision", "忽然一个喇嘛惨叫一声倒了下去。\n",room );
		if(objectp(man=present("lama",room))) man->die();		
		}
	}
	return 1;
	}
	else return notify_fail("你已经杀了六个喇嘛,不用再杀了。\n");
    }
return 1;
}

