// shedangao.c
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
		set("value", 100);
	}
	setup();
}

int do_eat(string arg)
{
	object me = this_player();
	if (!id(arg))
		return notify_fail("��Ҫ��ʲô��\n");
	if((me->query("max_jing")>=110)||(me->query("max_qi")>=200))
		return notify_fail("��ԡ��ߵ��ࡻ����Ч�ã�\n");
	if(me->query("max_jing")<105)
	   {me->add("max_jing", 2);
	    me->add("eff_jing", 2);
	    me->add("jing",4);
	    me->add("max_qi",5);
	    me->add("eff_qi", 5);
	    me->add("qi",10);
	   }
	else
	   {me->add("max_jing",1);
	    me->add("eff_jing", 1);
	    me->add("jing",2);
	    me->add("max_qi",3);
	    me->add("eff_qi", 3);
	    me->add("qi",5);
	    }
	message_vision( "$N����һ���ߵ��࣬�پ�һ�ɺƵ�����ֱӿ������
	����������...\n" , me);
	destruct(this_object());
	return 1;
}