//      chufang.c ����
//      Designed by secret (����)
//      97/04/09

inherit ROOM;

void init();
int work();

void create()
{
        set("short","����");
        set("long",@LONG
������ѩɽ�µĳ�����������ɮ�˿����ڴ˴��ӡ���
����Ŀ��λ����һ�����ӣ�paizi����
LONG );
        set("item_desc",([
                "paizi" : "�����������ӹ�������(work)һ�θ���ʮ����\n",
        ]));
        set("no_fight",1);
        set("no_steal",1);
        set("no_clean_up", 0);
        set("exits",([
                "south" : __DIR__"xiaoyuan",
        ]));
        set_temp("times" , 5);
        setup();
}

void init()
{
	add_action("do_work","work");
}

int do_work()
{
	object me=this_player();
        object ob;

        if (query_temp("times")==0)
                return notify_fail("����Ļ�����ˣ����������ɣ�\n");
        if(me->query("qi")<20)
		return notify_fail("�����̫���������ܹ�����\n");
	me->add("qi",-20);
	message_vision("$N����һЩ�ӻ�۵ù�Ǻ��\n" , me);
	add_temp("times",-1);

        ob=new("/clone/money/silver");
        ob->set_amount(10);
        ob->move(me);
	return 1;
}
