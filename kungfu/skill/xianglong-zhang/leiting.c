//leiting.c  ������һ����
#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
    int damage;
    string msg;

    if( !target ) target = offensive_target(me);

    if( !target || !target->is_character() || !me->is_fighting(target) )
   return notify_fail("��"+HIY"��"NOR+HIC"��"NOR+HIG"һ"NOR+HIR"��"NOR+"��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

    if( (int)me->query_skill("huntian-qigong", 1) < 100 )
   return notify_fail("��Ļ���������򲻹���ʹ������"+HIY"��"NOR+HIC"��"NOR+HIG"һ"NOR+HIR"��"NOR+"����\n");

    if( (int)me->query_skill("xianglong-zhang", 1) < 100 )
   return notify_fail("��Ľ���ʮ���Ʋ�������������ʹ�á�"+HIY"��"NOR+HIC"��"NOR+HIG"һ"NOR+HIR"��"NOR+"����\n");

    if( (int)me->query("neili") < 500 )
   return notify_fail("���������Ϊ�������ߡ�\n");

    msg = HIC "
$NĬ�˻���������ʩչ����"+HIY"��"NOR+HIC"��"NOR+HIG"һ"NOR+HIR"��"NOR+HIC+"����ȫ����ת��������Խ��Խ�죬������һ�����磬��Ȼ�䣬$N�Ѿ��������÷�����$n��\n"NOR;  

    if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/3) { 
      me->start_busy(3);
   target->start_busy(random(3));

   damage = (int)me->query_skill("xianglong-zhang", 1)*4+(int)me->query_skill("huntian-qigong",1);

   damage = damage + random(damage);

   target->receive_damage("qi", damage);
   target->receive_wound("qi", damage/2);
   me->add("neili", -500);
   msg += HIR"
$nֻ��һ������Ӱ�ж�Ȼ�ֳ�$N��˫ȭ��������������ܣ������ػ��У������������ڲ��ݣ�������Ѫ��������������\n"NOR;
    } else
    {
       me->start_busy(1);
       msg += HIG"����$p������$P����ͼ��������һ�ߡ�\n"NOR;
    }
    message_vision(msg, me, target);

    if(!target->is_fighting(me)) target->fight_ob(me);
//    if(userp(target)) target->fight_ob(me);
//    else if( !target->is_killing(me) ) target->kill_ob(me);
    return 1;
}

