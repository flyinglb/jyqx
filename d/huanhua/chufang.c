// chufang.c

inherit ROOM;

void create()
{
	set("short", "����ի");
	set("long", @LONG
����ԭ����һ�䲻��ĳ������и�������æµ�ţ��Ա߻��м��������ڰ�æ��
����ר��Ϊ����׼���ɿڵķ��ˣ���Ҳ����(order)һ�ݡ�
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
//       if (arg)  return notify_fail("Sorry, ������������û�а���\n");
    	if (query ("count_eat")>0)
        {
       message_vision("����æ����һֻ��Ѽ��һ���ƴ���$N\n",me);
	food=new(__DIR__"kaoya");
	water=new(__DIR__"jiudai");
	food->move(me);
	water->move(me);
	add("count_eat",-1);
        }
	else
	message_vision("�����Ѿ�û�ˡ�\n",me);
       return 1; 
}
