//
inherit ITEM;
void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name("�ߵ���", ({"shedan gao", "gao"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "�������Ʒ���ߵ��ࡻ��\n");
		set("value", 1000);
	}
	setup();
}

int do_eat(string arg)
{
	object me = this_player();
	if (!id(arg))
		return notify_fail("��Ҫ��ʲô��\n");
	if((me->query("max_jing")>=200)||(me->query("max_qi")>=200))
		return notify_fail("��ԡ��ߵ��ࡻ����Ч�ã�\n");
	if(me->query("max_jing")<180)
	   {me->add("max_jing", 10);
	    me->add("jing",10);
	    me->add("max_qi",10);
	    me->add("qi",10);
	   }
	else
	   {me->add("max_jing",2);
	    me->add("jing",2);
	    me->add("max_qi",2);
	    me->add("qi",2);
	    }
	message_vision( "$N����һ���ߵ��࣬�پ�һ�ɺƵ�����ֱӿ������
	����������...\n" , me);
	destruct(this_object());
	return 1;
}