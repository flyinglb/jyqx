#include <ansi.h>

inherit ITEM;


void init()
{
	add_action("do_eat", "eat");
	add_action("do_use", "use");
}

void create()
{
	set_name("�ٻ����߸�", ({"baihua gao", "gao","baihua"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "ö");
		set("long", "����һö���İٻ����߸ࡣ\n");
		set("value", 20000);
	}
	setup();
}

int do_eat(string arg)
{
	int force_limit, neili_limit ;

	object me = this_player();

	force_limit = me->query_skill("force")*10;
	neili_limit = me->query("max_neili");
	
	if (!id(arg)||(arg!="gao"&&arg!="baihua gao"))
	return notify_fail("��Ҫ��ʲô��\n");

	if ( neili_limit <= force_limit  )
	{
//		me->add("max_neili",random(50));
//		me->add("neili",25-random(50));
		me->add("eff_jing",10);

		message_vision(HIY "$N����һö�ٻ����߸࣬��Ȼ��ֻ��һ������֮��ֱ���ķ�...\n" NOR, this_player());
	}
	else
		message_vision(HIY "$N����һö�ٻ����߸࣬���Ǻ���ûʲô��.\n" NOR, this_player());

	destruct(this_object());
	return 1;
}

int do_use(string arg)
{

	object obj, weapon;
	object me = this_player();
	
	if (!id(arg)||(arg!="gao"&&arg!="baihua gao"))
		return notify_fail("��Ҫ��ʲô��\n");

        if (!objectp(weapon = me->query_temp("weapon")))
		return notify_fail("�����������²��аɣ�\n");

        message_vision(HIY "$Nȡ��һö�ٻ����߸࣬����Ĩ�ڱ��м�����֮��.\n" NOR, me);
        message_vision(HIY "$Nʹ�õİٻ����߸�ҩЧ��ʼ����.\n" NOR, me);
	obj=new("/d/shenlong/obj/usedgao");
        obj->move(me);
	destruct(this_object());
	return 1;
}

