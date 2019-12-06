// shantang.c
// shilling 97.2

inherit ROOM;

void create()
{
	set("short", "�Ƽ�");
	set("long", @LONG
����������¥���ӳԷ��ĵط����кö�óԵ�Ŷ!��������¥�����¸��
Ϊ�������׼���Ŀ��(order)һ�ݰɡ�
LONG );
	set("exits",([
		"west" : __DIR__"liangong8",
	]));
	set("no_clean_up", 0);
	set("ricewater", 15);
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
	if (arg)  return notify_fail("���ױĳ���˵��: ����Ժȣ���ȻҪû�еĶ������Ҵ�\n");
	if (query("ricewater")>0)
	{
		message_vision("һ��������������϶���һ��������Ŀ�Ѽ��һ���þƣ���԰�$N��\n",me);
		food=new(__DIR__"obj/kaoya");
		water=new(__DIR__"obj/jiudai");
		food->move(me);
		water->move(me);
		add("ricewater",-1);
	}
	else 
		message_vision("���ױĳ���˵��: �ˣ��ԵĺȵĶ�û�ˡ�\n",me);
	return 1; 
}
