inherit ITEM;

void init()
{
	add_action("do_eat", "eat");
}
void create()
{
	set_name(HIR"��"NOR"��"HIC"��"NOR"�"NOR, ({"chan"}));
	set("unit", "ֻ");
	set("value", 40000);
	set("long", "����һǧ���ѵ�һ�����쾦���, ͨ��͸��,
Ω�۳ʳ�ɫ, �ܽ�ٶ���\n");
	setup();
}

int do_eat(string arg)
{
	object me=this_player();
	if (!id(arg))  return notify_fail("��Ҫ��ʲô��\n");
	if (me->is_busy() )
		return notify_fail("�𼱣������ԣ�С�ı�ҭ���ˡ�\n");
	if(arg=="chan") 
	{
message_vision(HIG"$N����һֻ�쾦��󸣬ֻ��һ�����������ķΣ���ʱ��̨һƬ������������ˬ��\n" NOR, me);
		if (me->query_condition("drunk"))
			me->apply_condition("drunk",0);
		if (me->query_condition("flower_poison"))
			me->apply_condition("flower_poison",0);
		if (me->query_condition("ice_poison"))
			me->apply_condition("ice_poison",0);
		if (me->query_condition("iceshock"))
			me->apply_condition("iceshock",0);
		if (me->query_condition("rose_poison"))
			me->apply_condition("rose_poison",0);
		if (me->query_condition("sanxiao_poison"))
			me->apply_condition("sanxiao_poison",0);
		if (me->query_condition("scorpion_poison"))
			me->apply_condition("scorpion_poison",0);
		if (me->query_condition("slumber_drug"))
			me->apply_condition("slumber_drug",0);
		if (me->query_condition("snake_poison"))
			me->apply_condition("snake_poison",0);
		if (me->query_condition("ss_poison"))
			me->apply_condition("ss_poison",0);
		if (me->query_condition("xx_poison"))
			me->apply_condition("xx_poison",0);
		if (me->query_condition("zhua_poison"))
			me->apply_condition("zhua_poison",0);
		destruct(this_object());
	}
	me->start_busy(2);
	return 1;
}
