// slumber_drug.c

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	int limit;

	limit = (me->query("con") + (int)me->query("max_force") / 50) * 2;

	if( duration > limit
	&&	living(me) ) {
		me->unconcious();
		return 0;
	} else if( duration > limit/2 ) {
		tell_object(me, "��������л����������пյ����ģ�ֱ��������˯һ����\n");
		message("vision", me->name() + "ҡͷ���Ե�վ��վ���ȣ���Ȼ���ɺ�ҩ��ҩ�������ˡ�\n",
			environment(me), me);
	}

	me->apply_condition("slumber_drug", duration - 1);
	if( !duration ) return 0;
	return 1;
}
