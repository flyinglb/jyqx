// suck.c
#include <ansi.h>
inherit F_SSERVER;
int exert(object me, object target)
{
    int sp, dp;
    if ( target == me )
        target = offensive_target(me);
    if( environment(me)->query("no_suck") )
        return notify_fail("���������޷���ȡ������\n");
    if( !objectp(target) || target->query("id") == "mu ren" )
        return notify_fail("��Ҫ��ȡ˭��������\n");
    if ( me->query_temp("sucked") )
        return notify_fail("��ո���ȡ��������\n");
    if( (int)me->query_skill("beiming-shengong",1) < 50 )
        return notify_fail("��ı�ڤ�񹦹���������������ȡ�Է���������\n");
    if( (int)me->query("neili",1) < 20 )
        return notify_fail("�����������������ʹ�ñ�ڤ�񹦡�\n");
    if( (int)target->query("max_neili") <= 0 )
        return notify_fail( target->name() + "û���κ�������\n");
    if( (int)target->query("no_suck"))
        return notify_fail( target->name() + "û���κ�������\n");
    if( (int)target->query("neili") < 60  || !living(target))
        return notify_fail( target->name() +"�Ѿ�������ɢ�����Ѿ��޷�����������ȡ�κ������ˣ�\n");
    message_vision( HIM "$N����Ȼ�ӿ죬����ֱ�����͵ض�׼$n�����д�Ѩ������ȥ��\n\n" NOR, me, target );
    if ( living(target) )
    {
        if( !target->is_killing(me) )
            target->kill_ob(me);
    }
    sp = me->query_skill("force") + me->query_skill("dodge") + me->query_skill("lingboweibu",1)/2;
    dp = target->query_skill("force") + target->query_skill("dodge");
    me->set_temp("sucked", 1);      
    if (( random(sp) > random(dp) ) )
    {
        tell_object(target, HIR "��پ�ȫ��������ˮ����ѭ�׷�й������\n" NOR);
        tell_object(me, HIG "�����" + target->name() + "������������ԴԴ���������˽�����\n" NOR);
        target->add("neili", -1*((int)me->query_skill("beiming-shengong", 1) + target->query("jiali")) );
        if ( target->query("neili") <1 )
            target->set("neili",0);
        me->add("neili", (int)me->query_skill("beiming-shengong", 1) + target->query("jiali") );
        me->start_busy(random(5));
        target->start_busy(random(4));
        call_out("del_sucked", 2, me);
    }
    else
    {   
        message_vision(HIY "����$p������$P����ͼ����������˿�ȥ��\n" NOR, me, target);
        me->start_busy(4);
        call_out("del_sucked", 4, me);
    }
    return 1;
}
void del_sucked(object me)
{
    if (!me)    return;
    if ( me->query_temp("sucked"))
        me->delete_temp("sucked");
}
