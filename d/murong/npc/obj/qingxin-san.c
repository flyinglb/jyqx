// /u/beyond/obj/qingxin-san.c ��¶����ɢ
// this is made by beyond
// update 1997.6.23
#include <ansi.h>
inherit ITEM;
void setup()
{}
void init()
{
	add_action("do_eat", "eat");
}
void create()
{
	set_name("��¶����ɢ", ({"qingxin san", "san", }));   
	set("no_drop",1);
	set("no_get",1);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ��������������¶����ɢ����ҩ��Ľ��֮��ҩ�������������Ч�ޱȡ�\n");
		set("value", 10000);     
		set("no_drop",1);
	set("no_get",1);
		
	}

	set("murong",1);
	setup();
}

int do_eat(string arg)
{
	object me = this_player();

	if (!id(arg))
	return notify_fail("��Ҫ��ʲô��\n");

	if ( me->query_skill_mapped("force") != "shenyuan-gong")
	{
		if (me->add("max_jingli", -20) < 0)
			me->set("max_jingli", 0);
		if (me->add("eff_jingli", -20) < 0)
			me->set("eff_jingli", 0);
		message_vision(HIR "$N����һ����¶����ɢ��ֻ���øγ���ϣ�ԭ�������ڹ���������������������\n" NOR, me);
		me->unconcious();
		destruct(this_object());
		return 1;
	}

	if ( (int)me->query_condition("bonze_drug" ) > 0 )
	{
		if (me->add("max_jingli", -1) < 0)
			me->set("max_jingli", 0);
		if (me->add("eff_jingli", -1) < 0)
			me->set("eff_jingli", 0);
		message_vision(HIR "$N����һ����¶����ɢ��ֻ����ͷ�ؽ��ᣬҡҡ������ԭ����ʳ̫��̫�࣬ҩЧ�ʵ��䷴��\n" NOR, me);
	}
	else
	{
		me->add("max_jingli", 1);
		me->add("eff_jingli", 1);
		message_vision(HIY "$N����һ����¶����ɢ��ֻ�����������࣬������Ȼ��ߣ�\n" NOR, me);
		me->apply_condition("bonze_drug", 60);
	}
	
	destruct(this_object());
	return 1;
}

