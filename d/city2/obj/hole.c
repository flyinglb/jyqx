
inherit ITEM;
void dest();
void setup()
{}

void init()
{
        add_action("do_enter", "enter");
        add_action("do_enter", "down");
        call_out("dest", 20);
}

void create()
{
        set_name("����", ({"hole",}));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ����С�Ķ���\n");
                set("unit", "��");
                set("no_get", "���������Ҳ��?\n");
        }
        setup();
}


int do_enter(string arg)
{
	object me;
	me = this_player();
        if( !arg || arg!="hole" ) return 0;
		message("vision",
			me->name() + "һ��������������ȥ��\n",
			environment(me), ({me}) );
                me->move("/d/city2/andao1");
                message("vision",
			me->name() + "����������������\n",
                	environment(me), ({me}) );
		return 1;

}	


void dest()
{
	destruct(this_object());
	message("vision","\nͻȻ���������һ˫�������ƻصذ�Ѷ��ڵ�ס�ˡ�\n","/d/city2/neishi");
	message("vision","\n֨ѽһ�����������˰ѵذ�����ˡ�\n","/d/city2/andao1");
}




