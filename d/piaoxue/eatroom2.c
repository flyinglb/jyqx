inherit ROOM;

void create()
{
	set("short", "�׻��ò���");
	set("long", @LONG
������Ʈѩɽׯ�׻��õ����ò͵ĵط���
��������˵Ļ�������(order)һ�ݳԺȡ�
LONG );
	set("exits",([
		"north" : __DIR__"bhdian",
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
	message_vision("$N�ո�����س���ֻ�����з�����һ�ݷ����͵���$N����ǰ��\n",me);
		food=new(__DIR__"obj/food");
		water=new(__DIR__"obj/water");
		food->move(me);
		water->move(me);
		add("count_eat",-1);
	}
	else
	message_vision("�����Ѿ�û�ˡ�\n",me);
	return 1; 
}
