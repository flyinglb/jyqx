// Room: /guiyun/.c
// Date: Nov.18 1998 by Winder

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����ǹ���ׯ�ĳ�����һ�����¸����������æ��æȥ������
����������ĳ����ˡ�������Ӷ��ˣ��͸Ͽ��ҳ���Ҫ (serve)Щ
�Եİɡ�
LONG );
	set("no_clean_up", 0);
	set("exits", ([
		"south" : __DIR__"huayuan",
	]));
	set("ricewater", 5);
	setup();
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
	if (me->query("family/family_name") != "�һ���")
		return notify_fail("��������㲻���һ������ӣ�������ȡʳ�\n");
        if(present("zongzi",this_player()) || present("tea",this_player())) 
		return notify_fail("����������������ã����˷�ʳ�\n");
        if(present("zongzi",this_object()) || present("tea",this_object())) 
		return notify_fail("����������������ã����˷�ʳ�\n");
	if (query("ricewater")>0)
	{
		message_vision("����������Ӧ����$Nһ������һ�����ӡ�\n",me);
		food=new(__DIR__"obj/zongzi");
		water=new("/d/wudang/obj/xiangcha");
		food->move(me);
		water->move(me);
		add("ricewater",-1);
	}
	else 
		message_vision("�����$NǸ����: �ˣ��ԵĺȵĶ�û�ˡ�\n",me);
	return 1; 
}
int valid_leave(object me,string dir)
{
	me=this_player();
        if(dir=="south" && (present("zongzi",this_player()) || present("tea",this_player()))) 
             return notify_fail("����˵�������˾ͱ���ߡ�\n");
        return ::valid_leave(me,dir);
}
