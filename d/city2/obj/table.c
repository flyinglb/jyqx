inherit ITEM;

void init()
{
  add_action("do_climb", "climb");
  add_action("do_climb", "pa");
  add_action("do_move", "move");
  add_action("do_move", "yi");
}

void create()
{
        set_name("����", ({"table", "gongzhuo"}));
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
               set("long", "����һ���ľ������������һյ�͵ơ�\n");
               set("unit", "��");
               set("material", "wood");
               set("no_get", "\n���ò���.\n");
        }
        setup();
}

int do_climb(string arg)
{
        object me = this_player();
        int i;
	if (!id(arg)||arg!="table")
                return notify_fail("��Ҫ���Ķ�����\n");
        if (this_player()->query_temp("marks/��") ) {
                       write("����ô����û��û�ˣ�\n");
                        return 1;
        }
        else {
               message_vision("$N���Ϲ�����\n",this_player());         
		if (random(5) != 0)
		{
                this_player()->set_temp("marks/��", 1);
		return 1;
		}
		else
		{
		message_vision("\n$N���ֱ��ŵ����Ϲ�����һ��С�İ��͵�Ū���ˣ���\n", this_player());
		message_vision("�����������˻�$N���ϴ��Ż�ͻŻ���������������\n", this_player());
		i = (int)me->query_skill("dodge", 1) + random(50);
		if(i<50) { me->die(); return 1;}
		if(i<75) { me->unconcious(); return 1;}
		me->receive_damage("jing", 50 );
		me->receive_damage("qi", 50);
		return 1;
		}	
              }
}

int do_move(string arg)
{
        object ob,me = this_player();
	if (!id(arg)||arg!="table")
                return notify_fail("��Ҫ��ʲô��\n");
	if (!(ob = present("jin", this_player())))
	return notify_fail("��û�¶�����ʲô��\n");
	if (this_player()->query_temp("marks/��") ) {
        message_vision("$N�ְѹ������˻�ȥ��\n",me);
	this_player()->delete_temp("marks/��");
        }
        else {
        message_vision("$N�ѹ����ƿ���\n",me);
       this_player()->set_temp("marks/��",1);
	     }
return 1;
}
