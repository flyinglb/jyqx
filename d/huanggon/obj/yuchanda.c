inherit ITEM;
void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name("ѩ����󸵤", ({"yuchan dan", "dan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "\n���Ǹ�����������ҩ������ⶾ���ˣ�����Ƿ���\n");
		set("value", 10000);
	}
	setup();
}

int do_eat(string arg)
{
	object me = this_player();
	if (!id(arg))
		return notify_fail("��Ҫ��ʲô��\n");
/*	if(me->query("max_jing")<150)
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
*/	message_vision( "$N����һ��ѩ����󸵤��ֻ��һ�ɺƵ�����ֱӿ������
	��æ��ϥ��������Ŀ�˹�...\n" , me);
	destruct(this_object());
	return 1;
}