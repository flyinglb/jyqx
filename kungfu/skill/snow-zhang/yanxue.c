//yanxue.c  ����ѩ��÷��
#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
    int damage;
    string msg;

    if( !target ) target = offensive_target(me);

    if( !target || !target->is_character() || !me->is_fighting(target) )
   return notify_fail("��"+HIW"��ѩ��÷"NOR+"��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

    if( (int)me->query_skill("bingxue-xinfa", 1) < 100 )
   return notify_fail("��ı�ѩ�ķ���򲻹���ʹ������"+HIW"��ѩ��÷"NOR+"����\n");

    if( (int)me->query_skill("snow-zhang", 1) < 100 )
   return notify_fail("��ķ�ѩӳ÷�Ʋ�������������ʹ�á�"+HIW"��ѩ��÷"NOR+"����\n");

    if( (int)me->query("neili") < 400 )
   return notify_fail("���������Ϊ�������ߡ�\n");

    msg = HIW "
$N��ѩ�ķ���תһ���죬ȫ��ֻ��һ�ɺ���������������Хһ����\n"
"������ϣ�ʩչ����"+BLINK+"��ѩ��÷"+NOR+HIW+"����˫��һ��һ�ţ�һ��������Ѫ��\n"
"�����$n����ǵ�ϯ���ȥ��\n\n"NOR;

    if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2) { 
      me->start_busy(1+random(1));
   target->start_busy(random(1));

   damage = (int)me->query_skill("snow-zhang", 1)+(int)me->query_skill("bingxue-xinfa",1);

   damage = damage/2 + random(damage);

   target->receive_damage("qi", damage);
   target->receive_wound("qi", damage/4);
   me->add("neili", -300);
   msg += HIC"
$nֻ����������ϯ����������޿ɶ㣬��һ�Ӵ����㱻���������Ѫ������߷������Ʈȥ��\n\n"NOR;
    } else
    {
       me->start_busy(2+random(1));
       msg += HIC"����$p������$P����ͼ�������������һ�ߡ�\n\n"NOR;
    }
    message_vision(msg, me, target);

    if(!target->is_fighting(me)) target->fight_ob(me);
    return 1;
}


