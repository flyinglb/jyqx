inherit ROOM;

void create()
{
        set("short", "����");
	set("long", @LONG
����������ɽׯ�ĳ�����һ�������������æ��æȥ��������
��������ĳ����ˣ���������˵Ļ�������(order)һ�ݳԺȡ�
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
	message_vision("$N�ո�����س���ֻ�����з�����һ�ݷ����͵���$N����ǰ��\n",me);
		food=new(__DIR__"obj/food");
		water=new(__DIR__"obj/water");
		food->move(me);
		water->move(me);
	return 1; 
}
