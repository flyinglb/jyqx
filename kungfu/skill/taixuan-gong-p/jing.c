//jing.c  �����춯�ء�
#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
    int damage;
    string msg;

    if( !target ) target = offensive_target(me);

    if( !target || !target->is_character() || !me->is_fighting(target) )
   return notify_fail("��"+HIC"���춯��"NOR+"��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

    if( (int)me->query_skill("taixuan-gong", 1) < 200 )
   return notify_fail("���̫������򲻹����޷�ʩչ��"+HIC"���춯��"NOR+"����\n");

    if( (int)me->query("neili") < 1200 )
   return notify_fail("���������Ϊ�������ߡ�\n");

    msg = HIB "$NĬ��̫������ɲ�Ǽ����ذ����������ɳ��ʯ��\n"NOR;
    msg += HIB "$N��Ȼʩչ����"+HIC"���춯��"NOR+HIB+"����һ��������$n��\n"NOR;  

    if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2) { 
      me->start_busy(3);
   target->start_busy(random(3));

   damage = (int)me->query_skill("taixuan-gong", 1) * 5;

   damage = damage + random(damage);

   target->receive_damage("qi", damage);
   target->receive_wound("qi", damage/2);
   me->add("neili", -600);
   msg += HIR"
$nֻ�������һ�ɴ���ӿ�������޿ɶ㣬�����ػ��У��อ��������������������Ѫ���羨����������\n"NOR;
    } else
    {
       me->start_busy(1);
       msg += HIG"����$p������$P�Ĺ��ƣ���ΪѸ�ݵ����Ծ�������⡸"+HIC"���춯��"NOR+HIG+"�����˹�ȥ��\n"NOR;
    }
    message_vision(msg, me, target);

    if(!target->is_fighting(me)) target->fight_ob(me);
//    if(userp(target)) target->fight_ob(me);
//    else if( !target->is_killing(me) ) target->kill_ob(me);
    return 1;
}

