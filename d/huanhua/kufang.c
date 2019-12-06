// kufang.c
// written by tree

inherit ROOM;

void create()
{
	set("short", "库房");
	set("long", @LONG
这里一间不很大的瓦房，但经常有人来，屋中还有一张桌子，后面坐着个老头，
在不停的削着一根木头，嘴里还在嘟囔着：这些孩子，这么还跟小孩样的喜欢这些
木头玩具?桌子上面放在一些已经做好的玩具。你现在可以找他要木刀(yaodao)或
者是要木剑(yaojian)。
LONG
	);
	set("exits", ([
		"west" : __DIR__"xiaoyuan",
        ]));
	set("no_clean_up", 0);
        set("count_dao",6);
        set("count_jian",6);
	setup();
}
void init()
{
        add_action("do_yaodao","yaodao");
        add_action("do_yaojian","yaojian");
}

int do_yaodao(string arg)
{
       object me;
	object mudao;
       me=this_player();
//       if (arg)  return notify_fail("Sorry, 这样东西这里没有啊。\n");
       if (query ("count_dao")>0)
       {
       message_vision("老人没有吭声，从桌子上拿起一把木刀给$N\n",me);
	mudao=new(__DIR__"obj_mudao");
	mudao->move(me);
	add("count_dao",-1);
        }
	else
	message_vision("木刀已经没了。\n",me);
       return 1; 
}
int do_yaojian(string arg)
{
       object me;
	object mujian;
       me=this_player();
//       if (arg)  return notify_fail("Sorry, 这样东西这里没有啊。\n");
       if (query ("count_jian")>0)
       {
       message_vision("老人没有吭声，从桌子上拿起一把木剑给$N\n",me);
	mujian=new(__DIR__"obj_mujian");
	mujian->move(me);
	add("count_jian",-1);
        }
	else
	message_vision("木剑已经没了。\n",me);
       return 1; 
}
