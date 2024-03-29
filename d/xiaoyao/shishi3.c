// shishi3.c
// by shilling 97.2

inherit ROOM;
#include <ansi.h>;
void create()
{
	set("short", "石室");
	set("long", @LONG
这里是一个极大的石室，比之外面的任何一个都大了数倍，室中一排排
地列满了木制成的书架(shelf),可是书架上却空荡荡地连一本书也没有，走
近看时，只见书架上贴满了“昆仑派”，“少林派”，“青城派”之类的条
目，想象当年所列，皆是各门各派的武功秘籍。室中还有一张小床(bed)。
LONG );
	set("exits", ([
		"south" : __DIR__"shidong",
	]));
	set("item_desc", ([
		"bed"   : "一张很简陋的小床。\n",
		"shelf" : "书架上贴着一张小贴：“乘天地之正，御六气之辩，以游于无穷，是为逍遥。”\n",
	]));
	set("book1_count",1);
	set("no_clean_up", 0);
	setup();
}

void init()
{
        add_action("do_strike","strike");
        add_action("do_move","move");
}

int do_strike(string arg)
{
        object me;

        me=this_player();
        if(!arg || arg!="shelf") return 0;
        message_vision("$N看着看着，忽然猛的一掌向书架打去！震得书架“克拉，克拉”的响了几声。\n",me);
	if ( random(100) > 94)
	{
message_vision("忽然，$N听到一个声音嘿嘿地奸笑起来：“你上当啦！”\n",me);
message_vision("接着，不知道哪里射出一支毒箭，射中了$N！\n",me);
		me->die();
	}
        if (random(100)==50 && !present("miji1",me) && !present("blade_book2",me) && query("book1_count")>=1)
	{
     		add("book1_count", -1);
		me=new("/clone/book/blade_book2");
		me->move(__DIR__"shishi3");
message("channel:rumor", HIM"【"+HIR+"谣言"+HIM+"】"+HIR+"某人："+this_player()->query("name")+"得到了刀法进阶啦。\n"NOR, users());
		tell_object(me, "突然啪地一声，有一件东西从书架上掉了下来！\n");
	}
        return 1; 
}

int do_move(string arg)
{
	object me;

	me=this_player();
	if(!arg || arg!="bed") return 0;
	message_vision("$N用力把小床移开，发现里面竟然有一条秘密通道！\n",me);
	me->move(__DIR__"midao1");
	tell_object(me,"接着是一阵轰隆隆的响声，你定神一看，自己已经处身在秘密通道中了。\n");
	return 1; 
}
