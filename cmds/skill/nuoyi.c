// nuoyi.c Ǭ����Ų�ƴ�
// by King 97.05

#include <ansi.h>

inherit F_SSERVER;
int main(object me, string arg)
{
	string who1, who2;
	object target, victim;
        int damage, lvl, r_lvl, count, form, skill, i;
        string msg;

//        if( !me->query_skill("qiankundanuoyi", 1) )
        if( !me->query_skill("qiankun-danuoyi", 1) )
                return notify_fail("�㲻��Ǭ����Ų�ƴ󷨡�\n");

	if( !arg )
	{	target = offensive_target(me);
	        if( !target || !target->is_character() || !me->is_fighting(target) )
        	        return notify_fail("Ǭ����Ų�ƴ�ֻ�ܶ��Լ���ս���еĶ���ʹ�á�\n");
		form = 2;
	}
	else if( sscanf(arg, "%s to %s", who1, who2) == 2)
	{	target = present(who1, environment(me));
		victim = present(who2, environment(me));
	        if( !target || !target->is_character() || !me->is_fighting(target) )
       	        	return notify_fail("Ǭ����Ų�ƴ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	        if( !victim || !victim->is_character() || victim==me) 
			return notify_fail("����Ų�ƹ����Ķ��������\n");
		form = 3;
	}
	else 
	{	sscanf(arg, "%s", who1);
		target = present(who1, environment(me));
		if( target == me) form = 1;
	        else if( !target || !target->is_character() || !me->is_fighting(target) )
                	return notify_fail("Ǭ����Ų�ƴ�ֻ�ܶ��Լ���ս���еĶ���ʹ�á�\n");
		else form = 2;
	}

	if( me->is_busy() )
		return notify_fail("��Ķ�����û����ɣ����ܷ�����\n");

//        if( (int)me->query_skill("qiankundanuoyi", 1) < 50 )
        if( (int)me->query_skill("qiankun-danuoyi", 1) < 50 )
                return notify_fail("���Ǭ����Ų�Ʋ����ߣ�С���߻���ħ��\n");

        if( (int)me->query("neili", 1) < 1500 )
                return notify_fail("����������̫��������ʹ��Ǭ����Ų�ƴ󷨡�\n");

//    skill = (int)me->query_skill("qiankundanuoyi", 1);
    skill = (int)me->query_skill("qiankun-danuoyi", 1);
	lvl = skill/20;
	r_lvl = random(lvl);
	if( r_lvl < 1) r_lvl = 1;
	count = me->query_str();

	if( form == 1)
	{
		if( (int)me->query_temp("nuoyi") ) 
			return notify_fail("���Ѿ����˹����ˡ�\n");
		if( !me->is_fighting() )
			return notify_fail("Ǭ����Ų��ֻ����ս����ʹ�á�\n");
		message_vision( HIR"$NĬ��Ǭ����Ų�ƴ󷨣���ɫ������죬����"CYN + lvl + HIR"�Σ���ȫ��������������\n"NOR, me);
		me->add_temp("str", count * r_lvl);
		me->set_temp("nuoyi", 1);
		me->start_call_out( (: call_other, __FILE__, "remove_effect", me, count * r_lvl :), skill);
		me->add("neili", -300);
		me->start_busy(3);
		return 1;
	}

	if( form == 2 )
	{
        msg = CYN "$NĬ���񹦣�ʹ��Ǭ����Ų�ƴ󷨡�\n"NOR;
	me->start_busy(3);

        if (random(me->query("neili",1)) > 2*target->query("neili",1)/3 )
        {
                target->start_busy(random(3));
                
                damage = skill/2 + r_lvl*target->query("jiali",1);
                
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage/3);
                me->add("neili", -damage);
		msg += CYN "��$n������ȫ��������ȥ��\n" NOR;
                
                if( damage < 20 )
                        msg += HIY"���$n�ܵ�$N�����������ƺ�һ����\n"NOR;
        	else if( damage < 40 )
                        msg += HIY"���$n��$N���������𣬡��١���һ������������\n"NOR;
        	else if( damage < 80 )
                        msg += RED"���$n��$N������һ���ؿ������ܵ�һ���ش�����������������\n"NOR;
                else
                        msg += HIR"���$n��$N������һ����ǰһ�ڣ���һ������һ���ɳ�ȥ�ü���Զ��\n"NOR;
                
        }
        else 
        {
                msg += CYN"����$n�������˿����Ϊ������\n"NOR;
		me->add("neili", -100);
        }
        message_vision(msg, me, target);

	return 1;
	}

	if( form == 3 )
	{
	write( CYN "��Ĭ���񹦣�ʹ��Ǭ����Ų�ƴ󷨣���ͼ��" + target->name() + "�Ĺ���Ų�Ƶ�" + victim->name() + "���ϡ�\n"NOR);
	tell_object(target, CYN"��Ȼ���㷢����һ����ֵ���������Ϯ����\n"NOR);
	me->start_busy(3);

        if ( (random(me->query("neili",1)) > 2*target->query("neili",1)/3 ) && ( r_lvl > random(5) ) )
        {
                write( CYN"�������ɹ��ˣ�\n"NOR);

		if( target == victim)
		{
		tell_object(target, CYN"�����ɼ���һ�л����Լ���\n"NOR);
		message("vision", CYN"\n" + target->name() + "��Ȼ����ħһ�㣬���л����Լ���\n\n"NOR, environment(me), target);
		for(i = 0; i < r_lvl; i++)
			COMBAT_D->do_attack(target, victim, target->query_temp("weapon") );
		}

		else
		{
		tell_object(target, CYN"�����ɼ�����" + victim->name() + "��ȥ��\n"NOR);
		message("vision", CYN"\n" + target->name() + "��Ȼ��" + victim->name() +"��ȥ��\n\n"NOR, environment(me), ({target, victim}) );
		tell_object(victim, CYN"\n" + target->name() + "��Ȼ����������\n\n"NOR);

		COMBAT_D->do_attack(target, victim, target->query_temp("weapon") );

		if( random(me->query("combat_exp")) > (int)victim->query("combat_exp")/2 )		
		{
			if( !victim->is_killing(target) ) victim->kill_ob(target);
		}
		else
		{
		tell_object(victim, CYN"��һ����ԭ����" + me->name() + "�ڵ���\n"NOR);
		tell_object(target, CYN"���ã��ҿ�" + victim->name() + "�����ϵ���û���ϵ���\n"NOR);
		write( CYN "���ã���" + victim->name() + "�����ˣ�\n"NOR);
		if( !victim->is_killing(me) ) victim->kill_ob(me);
		}

                target->start_busy(random(3));
		me->add("neili", -300);
		}
	}
	else
	{
		write( CYN"��ϧû�ɹ���"NOR);
		tell_object(target, CYN"��ǿ���������ڿ���ס�Լ���\n"NOR);
		me->add("neili", -100);
	}

        return 1;
	}

	return 1;
}

void remove_effect(object me, int amount)
{
   if ( (int)me->query_temp("nuoyi") ) {
	me->add_temp("str", - amount);
	me->delete_temp("nuoyi");
	tell_object(me, "���Ǭ����Ų�ƴ�������ϣ��������ջص��\n");}
}

int help(object me)
{
write(@HELP
ָ���ʽ : 
1. nuoyi <�Լ�> : ���������Լ���ս������
2. nuoyi �� nuoyi <����> : ����������
3. nuoyi <����1> to <����2> : ����������1�Ĺ���Ų�Ƶ�����2���ϡ�
4. ���<3>��<����1>=<����2>������������зǳ���Ȥ������

HELP
    );
    return 1;
}
