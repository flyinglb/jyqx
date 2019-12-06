
inherit ITEM;

int do_move(string arg);

void init()
{
        add_action("do_move", "move");
}

void create()
{
        set_name("��", ({"picture",}));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "\nһ������ͨ��ˮī����\n");
                set("unit", "��");
                set("material", "paper");
                set("no_get", "\n����������������û�гɹ���\n");
        }
        setup();
}

int do_move(string arg)
{
        object me;
        object door;
	string dir;
        me = this_player();
        if (!arg||arg=="") return 0;
	if( arg=="picture" ) {
		if(!me->query_temp("doorisok"))
                message_vision("\n$N�����ƶ��������������������ƶ�...\n", this_player());
		if(!objectp(present("door", environment(me))))
                {
		message_vision(
		"$N�����Ų����ҳ��ͻȻһ�Ȱ��ų�����$N��ǰ��\n", this_player());
                door = new("/d/city2/obj/door");
                door->move("/d/city2/aobai7");
		}
	}
	if( sscanf(arg, "picture %s", dir)==1 ) {
		if( dir=="left" ) {
		message_vision("$N�����������ƣ�ֻ�������������������ƻ�ԭλ��\n", this_player());
	        if(!me->query_temp("pushdoor"))
	        me->set_temp("pushdoor", 1);
	        else 
	        me->set_temp("pushdoor", 0);
		return 1;
        	}
		if( dir=="right" ) {
			message_vision("$N�����������ƣ�ֻ�������������������ƻ�ԭλ��\n", this_player());
		if (me->query_temp("pushdoor") )        
        	 	{
			me->set_temp("doorisok", 1); 
			me->delete_temp("pushdoor");
			}
                return 1;
		}
		else {
			write("��Ҫ�����������Ǹ�����\n");
			return 1;
		      }
	}
return 1;
}


