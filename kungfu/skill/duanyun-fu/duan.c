//duan.c -��������֮������ն��
// Modified by Venus Oct.1997
#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
int perform(object me, object target)
{
    int damage;
    string msg;
    if( !target ) target = offensive_target(me);
    if( !target||!target->is_character()||!me->is_fighting(target) )
    return notify_fail("��ֻ�ܶ�ս���еĶ���ʹ�á�����ն����\n");
    if( (int)me->query_skill("duanyun-fu",1) < 70)
    return notify_fail("��Ŀǰ������ʹ����������ն����\n");
    if( (int)me->query("neili") < 200 )
    return notify_fail("�������������\n");
    me->add("neili", -60);
msg = HIC"$NͻȻ����һ���������о޸�б���Ͼ���Ȼ���ڰ���л���һ
��Բ�����漴��ֱб��ն��$n����һ˲�䣬$nֻ���ú�����ֹͣ�ˣ�\n"NOR;
    me->start_busy(3);

    if( random(me->query("combat_exp")) >
      (int)target->query("combat_exp")/8 ) {
    target->start_busy( (int)me->query_skill("duanyun-fu") / 80 );
    damage = (int)me->query_skill("duanyun-fu", 1)+(int)me->query_skill("axe", 1
)/2;
    damage = damage/2 + random(damage);

    target->receive_damage("qi", damage/2);
    target->receive_wound("qi", damage/2);
   msg += RED
"ֻ��$n��$Nһ�����У���ǰ�ѿ�һ��������˿ڣ�Ѫ��������������\n"NOR;
    } else {
    msg += HIC "����$p��æ����㿪��$P����û�еóѡ�\n" NOR;
    me->start_busy(3);
    }
    message_vision(msg, me, target);
    return 1;
}

