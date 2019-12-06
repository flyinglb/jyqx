//RJQMENLOU3.C

inherit ROOM;

void create()
{
	set("short", "��¥����");
	set("long", @LONG
������һ���ʯ�ң�����ڷ���ʯ��(zhuo)ʯ��(chair)��ʯ��
�Ͽ����ݺύ���ͼ������ϸ����ԭ����һ��֣�����������(hei
zi)��һ��(bai zi)�����ð׷������ˡ�ȴ��֪���ĵ���ʿΪ��û��
���ꡣ
LONG );
	set("exits", ([
//		"up" : __DIR__"rjqmenlou3",
		"down" : __DIR__"rjqmenlou2",
	]));
	set("no_clean_up", 0);
//	set("outdoors", "mingjiao");
	setup();
//	replace_program(ROOM);
}

void init()
{
	add_action("do_push", "push");
	add_action("do_sit", "sit");
}

int do_sit(string arg)
{

	if ( !arg || (arg != "chair") )
		return notify_fail("��һ�����˸�ƨ�ɶա�\n");	
	
	if (this_player()->query_temp("allsit")==1)
		return notify_fail("���Ѿ������ˡ�\n");	
			
	this_player()->set_temp("allsit", 1);
	return notify_fail("�����˸����������£���ʼ˼����֡�\n");	
}

int do_push(string arg)
{
	object me;
	me=this_player();
	if(me->query_temp("allsit")!=1)
	{
		message_vision("$Nֻ����һ���㱣������˵��ϡ�\n", me);
                me->set_temp("hei",0);
                me->set_temp("allsit",0);		
		me->unconcious();
		return notify_fail("\n");
	}
	if ((arg!="hei zi")&&(arg!="bai zi"))
		return notify_fail("�����ᰴ��һ��ʯ��������һ�����ѽ��\n");
	if(me->query_temp("allsit")&&(arg=="hei zi"))
	{
		if(me->query_temp("hei")==2)
		{
			me->set_temp("hei", 0);
			return notify_fail("�����ᰴ��һ�º����ӣ�ʲô��ӦҲû�С�\n");
		}
		else if(me->query_temp("hei")==1)
		{
			me->set_temp("hei", 2);
			return notify_fail("�����ᰴ��һ�º����ӣ�ʲô��ӦҲû�С�\n");
		}
		else if(me->query_temp("hei")==0)
		{
			me->set_temp("hei", 1);		
			return notify_fail("�����ᰴ��һ�º����ӣ�ʲô��ӦҲû�С�\n");
		}
	}
	if(me->query_temp("allsit")&&(arg=="bai zi"))
	{
		if(me->query_temp("hei")!=2)
				return notify_fail("�����ᰴ��һ�°����ӣ�ʲô��ӦҲû�С�\n");	
		if(me->query_temp("hei")==2)
		{
			message_vision("ֻ��ʯ���͵�һ����$Nһ���ҽУ�ֱ��������ȥ�ˡ�\n", me);
//			message_vision("ʯ����Ѹ�ٵػָ���ԭ״\n");
		        me->set_temp("hei",0);
                        me->set_temp("allsit",0);		
//			command("recruit " + me->query("id"));
			me->move("/d/mingjiao/rjqmidao");
				return notify_fail("\n");				
		}
	}
}			

int valid_leave(object me, string dir)
{
    me->set_temp("hei",0);
    me->set_temp("allsit",0);		
    return ::valid_leave(me, dir);
}

