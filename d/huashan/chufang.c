//chufang.c
inherit ROOM;
void create()
{
	set("short","����");
	set("long",@LONG
���ǻ�ɽ�ɵĳ�����һλ��ɽСʦ�������շ����������������ŷ���
�㡣�������Сʦ��Ҫ(serve) Щ�Եĺȵġ�ǽ������һ������(note)��
LONG);
	set("exits",([
		"east" : __DIR__"garden",
	]));
	set("item_desc",([
		"note" : "һ��һ������˼��֮���ס�\n",
	]));
	set("objects",([
		__DIR__"npc/girldizi" : 1,
	]));
//	set("no_clean_up", 0);
	set("ricewater", 5);
	set("no_fight","1");
	setup();
}
int valid_leave(object me, string dir)
{
	if ( present("soup", me) || present("rice", me))
	return notify_fail("Сʦ�õ�����һ��: �Բ���Ҫ�����߰�? \n");
	return ::valid_leave(me, dir);
}

void init()
{
        add_action("do_serve","serve");
}

int do_serve()
{
	object me;
	object food;
	object water;
	me=this_player();
	if (me->query("family/family_name") != "��ɽ��")
		return notify_fail("Сʦ�õ����㲻�ǻ�ɽ�ɵ��ӣ�������ȡʳ�\n");
        if(present("rice",this_player()) ) 
		return notify_fail("Сʦ�õ������������ã����˷�ʳ�\n");
        if(present("rice",this_object()) ) 
		return notify_fail("Сʦ�õ������������ã����˷�ʳ�\n");
	if (query("ricewater")>0)
	{
		message_vision("Сʦ��������Ӧ����$Nһ����׷���һ���ʹ�����\n",me);
		food=new(__DIR__"obj/rice");
		water=new(__DIR__"obj/soup");
		food->move(me);
		water->move(me);
		add("ricewater",-1);
	}
	else 
		message_vision("Сʦ�ö�$NǸ����: �ˣ��ԵĺȵĶ�û�ˡ�\n",me);
	return 1; 
}
