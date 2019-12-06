
inherit ITEM;
void dest();
void setup()
{}

void init()
{
        add_action("do_enter", "enter");
        add_action("do_enter", "knock");
        add_action("do_enter", "break");
        call_out("dest", 50);
}

void create()
{
        set_name("����", ({"door",}));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ����С�İ��š�\n");
                set("unit", "��");
                set("material", "wood");
                set("no_get", "���������ҲҪ?\n");
        }
        setup();
}


int do_enter(string arg)
{
	object me;
	int i,ging_cost, qi_cost;
	me = this_player();

        if( !arg || arg=="" ) return 0;
	if (me->query_temp("doorisok") ) 
        {
	me->delete_temp("doorisok"); 
	message("vision","���ڿ���������.\n",environment(me));
        return 1;
        }
        if( arg=="door" ) 
	{
		message_vision("$N�����˻��أ�\n", this_player());
		message("vision","ͻȻ���������һ�µ����ˣ�����ײ��"+me->name()+"��ͷ��\n",environment(me));
	        i = (int)me->query_skill("dodge", 0);
		ging_cost = 700 / (int)me->query("int");
		qi_cost = 500 / (int)me->query("int");
		me->receive_damage("jing", ging_cost );
		me->receive_damage("qi", qi_cost );
                if(i>100||i<30) me->unconcious();
		return 1;
	}
}	


void dest()
{
	message("vision","����ͻȻ�Զ��ƻأ��ְѰ��������ˡ�\n","/d/city2/aobai7");
	destruct(this_object());
}




