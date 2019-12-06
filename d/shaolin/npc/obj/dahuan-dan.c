// dahuan-dan.c �󻹵�

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
	set_name("�󻹵�", ({"dahuan dan", "dahuan", "dan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ���Ϻ쾧���Ĵ󻹵����˵���������ҩ����߹�������Ч�ޱȡ�\n");
		set("value", 10000);
		set("no_drop", "�������������뿪�㡣\n");
	}

	set("shaolin",1);
	setup();
}

int do_eat(string arg)
{
	int force_limit, neili_limit;

	object me = this_player();

	force_limit = me->query_skill("force")*10;
	neili_limit = me->query("max_neili");
	
	if (!id(arg))
		return notify_fail("��Ҫ��ʲô��\n");

	if( me->is_busy() )
		return notify_fail("�𼱣������ԣ�С�ı�ҭ���ˡ�\n");

	me->start_busy(2);
	if ( me->query_skill_mapped("force") != "hunyuan-yiqi" )
	{
		me->add("max_neili", -10);
		message_vision(HIR "$N����һ�Ŵ󻹵���ֻ���øγ���ϣ�ԭ�������ڹ�����������������Ԫ��\n" NOR, me);
//		me->unconcious();
		destruct(this_object());
		return 1;
	}

	if ( (int)me->query_condition("bonze_drug" ) > 0 )
	{
		me->add("max_neili", -1);
		message_vision(HIR "$N����һ�Ŵ󻹵���ֻ����ͷ�ؽ��ᣬҡҡ������ԭ����ʳ̫��̫�࣬ҩЧ�ʵ��䷴��\n" NOR, me);
	}
	else if ( neili_limit <= force_limit  )
	{
		me->add("max_neili", 1);
		message_vision(HIG "$N����һ�Ŵ󻹵���ֻ������������ԴԴ���������Ϲ���������
͸ʮ����¥���鲼��������ȫ������Ȼ��� !\n" NOR, me);
	}

	me->apply_condition("bonze_drug", 60);
	
	destruct(this_object());
	return 1;
}

