// san.c  ��Ůɢ��
#include <ansi.h>
inherit F_SSERVER;
int perform(object me, object target)
{
    object weapon;
    int damage;
    string msg;
    if( !target ) target = offensive_target(me);
    if( !target || !target->is_character() || !me->is_fighting(target) )
        return notify_fail("����Ůɢ����ֻ�ܶ�ս���еĶ���ʹ�á�\n");
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "sword")
    if (!objectp(weapon = me->query_temp("secondary_weapon"))
    || (string)weapon->query("skill_type") != "sword")
        return notify_fail("��ʹ�õ��������ԡ�\n");
        
    if( (int)me->query_skill("tianyu-qijian", 1) < 80 )
        return notify_fail("��������潣������죬����ʹ�á�\n");
    if (!me->visible(target))    return notify_fail("�㿴����"+target->name()+"��\n");
                            
  if( (string)me->query_skill_mapped("force")!="bahuang-gong" || (int)me->query_skill("bahuang-gong", 1) < 50 )
        return notify_fail("��İ˻�����Ψ�Ҷ���û��׼�����������ߡ�\n");
    if( (int)me->query("neili", 1) < 300 )
        return notify_fail("����������̫��������ʹ�á���Ůɢ������\n");
            
    msg = HIM "$N����Ϣ�������󼲶���ʹ�������潣�еľ���--����Ůɢ������ֻ��ǧ�����������ǵط���$n��\n\n"NOR;
  if( !target->is_killing(me) ) target->kill_ob(me);
    if (random(me->query_skill("force")) > target->query_skill("force")/3 )
    {
        target->start_busy( (int)me->query_skill("tianyu-qijian") / 20 + 2);
        
        damage = (int)me->query_skill("tianyu-qijian", 1);
        damage = damage +  (int)me->query_skill("bahuang-gong", 1)* 0.5;
        damage = damage +  (int)me->query_skill("sword", 1)* 0.75;
        
        target->receive_damage("qi", damage,me);
        target->receive_wound("qi", damage/2,me);
        me->add("neili", -damage/2);
        msg += HIR"$nֻ��һ���������Ķ�������ͷһ����Ѫ���������\n"NOR;
        me->start_busy(6);
    } else 
    {
        msg += YEL"����$p�͵����һԾ,������$P�Ĺ�����Χ��\n"NOR;
        me->add("neili", -100);
        me->start_busy(3);
    }
    message_vision(msg, me, target);
    return 1;
}

