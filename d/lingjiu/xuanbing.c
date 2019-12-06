//ROOM xuanbing.c

inherit ROOM;

void init();
int do_climb(object me);
int do_xia(object me);
	
void create()
{
        set("short","������");
	set("long",@LONG
���������ڹ��ĵط��� ����������һ��ǧ������(ice)������ð��˿
˿������ ������˺������ˣ��㲻�ɵô���һ��������
LONG );
        set("exits", ([
		"east" : __DIR__"changl13",
        ]));
	set("item_desc", ([
	    "ice" : "����һ�������ɽ֮�۵�ǧ������,��˵������������°빦��.\n�����������(climb)��ȥ.\n",
	]));
	set("no_clean_up", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	object where;
	me=this_player();
        where=environment(me);
	if (dir == "east" && where->query("xuanbing"))
         return notify_fail("�㻹û�µ�(down)�أ��������ܡ�\n");
	return ::valid_leave(me, dir);
}

void init()
{
	add_action("do_climb", "climb");
        add_action("do_xia", "down");
}

int do_climb(object me)
{      
        me=this_player();
	if(!me->query_skill("bahuang-gong", 1)||(int)me->query_skill("bahuang-gong", 1) < 10)
	   {
		write("��İ˻�����Ψ�Ҷ�����Ϊ���������������溮��\n");                   
		message_vision("$N�Ѿ�������������,��������òҲҵģ��Ͻ�����������\n",me);
		return 1; 
 	  }	
	message_vision("$N�Ѿ�������������,���ڴ������������ˡ�\n",me);
	set("xuanbing",1);
	return 1;	
}

int do_xia(object me)
{
	object where;
	me=this_player();
	where=environment(me);	
	if (!where->query("xuanbing"))
	 return notify_fail("����û�����������µ���ȥѽ����\n");
	set("xuanbing",0);
	message_vision("$N���깦��������������µ�����\n",me);
	return 1;
}
