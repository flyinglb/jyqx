// Room: /d/xiangyang/juyichufang.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����Ǿ���ݵĳ�����һ��ֻ�а����м����շ�ʦ������
����������Ӧ��serve����ʳ���������ϾͿ���������ˡ�
LONG );
	set("exits", ([
		"north" : __DIR__"juyihuayuan",
	]));
	set("objects", ([
		__DIR__"npc/shaofanshifu" : 1,
	]));
	set("no_fight", 1);
	set("ricewater", 30);
	setup();
}

int valid_leave(object me, string dir)
{
	if ( present("soup", me) || present("rice", me))
	return notify_fail("�շ�ʦ������һ˫���ۣ��Բ���Ҫ�����߰���\n");
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
        if(present("rice",this_player()) ) 
		return notify_fail("�շ�ʦ���������������ã����˷�ʳ�\n");
        if(present("rice",this_object()) ) 
		return notify_fail("�շ�ʦ���������������ã����˷�ʳ�\n");
	if (query("ricewater")>0)
	{
		message_vision("�շ�ʦ����$Nһ������׷���һ��Ұ������\n",me);
		food=new(__DIR__"obj/rice");
		water=new(__DIR__"obj/soup");
		food->move(me);
		water->move(me);
		add("ricewater",-1);
	}
	else 
		message_vision("�շ�ʦ����$NǸ����: �ˣ��ԵĺȵĶ�û�ˡ�\n",me);
	return 1; 
}
