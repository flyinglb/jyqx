//
// fanchang.c
// by secret
// 97-1-16
//
#include <ansi.h>
inherit F_SSERVER;
int exert(object me, object target)
{
    int sp, dp;
    if ( target == me )
        target = offensive_target(me);
    if( !objectp(target) || target->query("id") == "mu ren" )
        return notify_fail("��Ҫ����˭��\n");
    if (!living(target))
        return notify_fail("�Ѿ�����ҪΪ"+target->name()+"�˷Ѹ���ˣ�\n");
    if( (int)me->query_skill("longxiang",1) < 50 )
        return notify_fail("�����������������������������񹥻��Է���\n");
    if( (int)me->query("neili",1) < 50 )
        return notify_fail("�����������������ʹ�������������\n");
    message_vision(HIW "$N���ޱ��飬�������󳪰����$n���У�\n\n" NOR, me, target );
    if( living(target))
        if( !target->is_killing(me) )
            target->kill_ob(me);
    sp = me->query_skill("force") + me->query_skill("lamaism") + me->query_skill("longxiang",1)/2;
    dp = target->query_skill("force");
    
    if (( random(sp) > random(dp) ) )
    {
        tell_object(target, HIW " ���Ȼ��������һƬ�հף�����������������赸������\n" NOR);
        tell_object(me, HIB "�㿴��" + target->name() + "������ĸ��������㵸��ʮ�ֿ�Ц��\n" NOR);
        target->receive_wound("jing", 10 + random((int)me->query_skill("longxiang", 1)),me );
        me->start_busy(2);
        target->start_busy(random(3));
        me->add("neili", -50);
    }
    else
    {   
        message_vision(HIY "����$p��Ϊ$P����������������Ȼ��ͬ���죡\n" NOR, me, target);
        me->start_busy(4);
    }
    return 1;
}

