// drunk.c

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	int limit;

	limit = (me->query("con") + (int)me->query("max_neili") / 50) * 2;

	if( duration > limit
	&&	living(me) ) {
		me->unconcious();
		return 0;
	} else if( !living(me) ) {
		message("vision", me->name() + "���˸��ã�������Ȼ�������ࡣ\n",
			environment(me), me);
	} else if( duration > limit/2 ) {
		tell_object(me, "��������л�������������ƮƮ�أ���������ˡ�\n");
		message("vision", me->name() + "ҡͷ���Ե�վ��վ���ȣ���Ȼ�Ǻ����ˡ�\n",
			environment(me), me);
		me->receive_damage("jing", 10);
	} else if( duration > limit/4 ) {
		tell_object(me, "�����һ������ϳ壬��Ƥ��Щ�����ˡ�\n");
		message("vision", me->name() + "�����Ѿ����Ծ����ˡ�\n",
			environment(me), me);
		me->receive_healing("jing", 10);
		me->receive_healing("qi", 15);
	}

	me->apply_condition("drunk", duration - 1);
	if( !duration ) return 0;
	return 1;
}
