// throw.c ���޶���ʩ��
// By Yzuo 97.04
#include <ansi.h>
inherit F_SSERVER;
int perform(object me, object target)
{
      object obj;
    string msg;
    if( !target ) target = offensive_target(me);
    if( !target || !target->is_character() )
        return notify_fail("ʩ��ֻ�ܶԶ���ʹ�á�\n");
    if( (int)me->query_skill("huagong-dafa", 1) < 40 )
        return notify_fail("��Ļ����󷨲�����죬����ʩ����\n");
    if( (int)me->query_skill("xingxiu-duzhang", 1) < 40 )
        return notify_fail("������޶��Ʋ�����죬����ʩ����\n");
    if ( !(objectp(obj=present("corpse", environment(me))) 
        || objectp(obj=present("corpse", me))
        || objectp(obj=present("Skeleton", environment(me)))
        || objectp(obj=present("Skeleton", me)) ) )
        return notify_fail("����Χû��ʬ�塣\n");
    msg = CYN "$N˳��ץ��ʬ�壬�������������ϣ�����$n��\n";
    me->start_busy(1);
    if( random( (int)me->query_skill("xingxiu-duzhang",1))
          > random(target->query_skill("dodge") ) ) {
        msg += CYN " ���$p��$P���˸����ţ�\n" NOR;
            target->receive_damage("qi",(int)me->query_skill("xingxiu-duzhang",1),me);
            target->receive_wound("qi",15 + random(10),me);
            target->receive_wound("jing", 10,me);
            target->apply_condition("xx_poison", random(me->query_skill("xingxiu-duzhang",1)/10) + 1 +
            target->query_condition("xx_poison"));
            target->start_busy(1 + random(2));
    } else {
        msg += "����$p��æ����һ�ԣ����˿�ȥ��\n" NOR;
        me->start_busy(4);
    }
    message_vision(msg, me, target);
    if( !target->is_killing(me) ) target->kill_ob(me);
      destruct(obj);
    return 1;
}
