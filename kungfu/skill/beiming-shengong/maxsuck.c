// maxsuck.c
#include <ansi.h>
inherit F_SSERVER;
int exert(object me, object target)
{
    int sp, dp,max_suck;
    if ( target == me )
        target = offensive_target(me);
    if( environment(me)->query("no_suck") )
        return notify_fail("���������޷���ȡ������\n");
    if( !objectp(target) || target->query("id") == "mu ren" )
        return notify_fail("��Ҫ��ȡ˭��������\n");
    if ( me->query_temp("sucked") )
        return notify_fail("��ո���ȡ��������\n");
    if( (int)me->query_skill("beiming-shengong",1) < 90 )
        return notify_fail("��ı�ڤ�񹦹���������������ȡ�Է����������\n");
    if( (int)me->query("neili",1) < 20 )
        return notify_fail("�����������������ʹ�ñ�ڤ�񹦡�\n");
    if( (int)target->query("max_neili") < 60  || !living(target))
        return notify_fail( target->name() +
            "�Ѿ�������ɢ�����Ѿ��޷�����������ȡ�κ������ˣ�\n");
    message_vision(
        HIM "$N������Ȼ�ӿ죬����ֱ�����͵ض�׼$n�����д�Ѩ������ȥ��\n\n" NOR,
        me, target );
    if ( living(target) )
    {
//        if( !target->is_killing(me) )
            target->kill_ob(me);
            me->kill_ob(target);
    }
    if( wizardp(target) || (int)target->query("max_neili") <= 0 || (int)target->query("no_suck"))
        return notify_fail( target->name() + "û���κ�������\n");
    sp = me->query_skill("force") + me->query_skill("dodge") + me->query_skill("lingboweibu",1)/2;
    dp = target->query_skill("force") + target->query_skill("dodge");
    me->set_temp("sucked", 1);      
    if (( random(sp) > random(dp) ) )
    {
        tell_object(target, HIY "��پ�ȫ��������ˮ����ѭ�׷�й������\n" NOR);
        tell_object(me, HIG "�����" + target->name() + "������������ԴԴ���������˽�����\n" NOR);
        max_suck=(int)target->query("max_neili") - (int)me->query("max_neili")/2;
        max_suck=max_suck/60+(int)me->query_skill("beiming-shengong", 1) + target->query("jiali");
        if (max_suck<1) max_suck=1+random(2);
        else max_suck/=20;
        target->add("max_neili",  -max_suck );

        me->add("max_neili",  max_suck );
        if( (int)me->query("potential") - (int)me->query("learned_points") < 90 )
        me->add("potential", 2);
        me->add("combat_exp", 10);
        if ( target->query("max_neili") <1 )
            target->set("max_neili",0);
        me->start_busy(random(5)+5);
        target->start_busy(random(3)+3);
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
