// xiaolu2.c

inherit ROOM;

void create()
{
	set("short", "Сɽ·");
	set("long", @LONG
�����ǻ�ɽ��һ��Сɽ·�����ƽ�Ϊƽ�������������ط���ô�վ���
������������ܾ����ĵģ�������߽���һ��������Դ�����������һ
������(men)��
LONG );
	set("exits", ([ /* sizeof() == 1 */
		"southwest" : __DIR__"xiaolu1",
	]));
	set("no_clean_up", 0);
	set("outdoors", "huashan" );
        set("no_clean_up", 0);

	setup();
}

void init()
{
    add_action("do_knock", "knock");
    add_action("do_push", "push");
}

int close_men()
{
    object room;

    if(!( room = find_object(__DIR__"xiuxishi")) )
        room = load_object(__DIR__"xiuxishi");
    if(objectp(room))
    {
        delete("exits/east");
        message("vision", "��֨֨ѽѽ���Լ������ˡ�\n", this_object());
        room->delete("exits/west");
        message("vision", "��֨֨ѽѽ���Լ������ˡ�\n", room);
    }
    else message("vision", "ERROR: men not found(close).\n", room);
}

int do_knock(string arg)
{
    object room;

    if (query("exits/east"))
        return notify_fail("�����Ѿ��ǿ����ˡ�\n");

    if (!arg || (arg != "door" && arg != "men"))
        return notify_fail("��Ҫ��ʲô��\n");

    if(!( room = find_object(__DIR__"xiuxishi")) )
        room = load_object(__DIR__"xiuxishi");
        
    if(objectp(room))
	{
		if ((int)room->query_temp("sleeping_person") > 0)
		{
        	message_vision(
"$N�����������һ���ţ����������洫��һ���������������\n"
"��Ȼ�������˯�ø������Ƶģ���ô�ö�û����\n",
			this_player());
		}
		else if ((int)room->query_temp("person_inside") > 0)
		{
			switch( random(2) )
			{
				case 0:
        			message_vision(
"$N������������ţ�ֻ�����������˺ܲ��ͷ��غ𵽣�\n"
"�����¾������ţ���˯���ˣ�������������\n",	this_player());
					break;
				case 1: 
					message_vision(
"$N������������ţ�ֻ����������Щ�춯��\n"
"����������������ȥ���ò��������Ƿ��š�\n", this_player());
					break;
			}       	
		}
		else
		{
			room->delete_temp("sleeping_person");
			message_vision("$N������������ţ��ˡ��ˡ��ˣ������ˡ��ˡ��ˣ�����\n",
            this_player());
		}
	}

    if(objectp(room))
    	message("vision",
    	"���洫��һ��������������ŷ�����һ�ƣ���"+this_player()->query("name")+"һ��������վ�����⣬\n"
    	"������Ҳ�������Ϣ��\n", room);
        
    return 1;
}

int do_push(string arg)
{
    object room;

    if (query("exits/east"))
        return notify_fail("���Ѿ��ǿ����ˡ�\n");

    if (!arg || (arg != "door" && arg != "men"))
        return notify_fail("��Ҫ��ʲô��\n");

    if(!(room = find_object(__DIR__"xiuxishi")))
        room = load_object(__DIR__"xiuxishi");
        
    if(objectp(room))
    {
		if((int)room->query_temp("person_inside")<=0)
		{
			room->delete_temp("person_inside");
			set("exits/east", __DIR__"xiuxishi");
			message_vision("$N����ذ����ƿ���\n", this_player());
			room->set("exits/west", __FILE__);
			remove_call_out("close_men");
			call_out("close_men", 10);
		}
		else 
		{
			message_vision("$N������ƿ���ȴ�����ű��˴����������ˡ�\n",this_player());
		}
	}

    return 1;
}

string look_men()
{
    object room;

    if (query("exits/east"))
		return ("���Ϲ��˸����ӣ���ɽС��\n");

    if(!( room = find_object(__DIR__"xiuxishi")) )
        room = load_object(__DIR__"xiuxishi");

    if( objectp(room) )
    if( (int)room->query_temp("person_inside") > 0 )
    {
		return ("���Ϲ��˸����ӣ�����һ�Ρ���������!\n");
    } 
    
    return ("���Ϲ��˸����ӣ���ɽ����Ϣ��\n");
}

int valid_leave(object me, string dir)
{
	object room;
    	
	if(!( room = find_object(__DIR__"xiuxishi")) )
		room = load_object(__DIR__"xiuxishi");

	if(objectp(room) && dir == "east")
	{
		room->add_temp("person_inside", 1);
		// will open the door if ppl inside stay too long 
		remove_call_out("force_open");
		call_out("force_open", 299, room);
	}		

	return ::valid_leave(me, dir);
}

int force_open(object room)
{
	if(!objectp(room))
		return 0;
    if((int)room->query_temp("person_inside") <= 0)
		return 0;
    
	room->delete_temp("person_inside");
    set("exits/east", __DIR__"xiuxishi");
    room->set("exits/west", __FILE__);
    message("vision", "����ͻȻ������صĽŲ�������Զ����������ǰͣ������������\n"
    	"½����ž�ذ��Ŵ򿪣����ͷ������һ�����ɣ���������˻�����ȥ����ʲô��\n", room);
    remove_call_out("close_men");
    call_out("close_men", 10);
}
