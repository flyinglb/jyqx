// jingsuck.c
#include <ansi.h>
inherit F_SSERVER;
int exert(object me, object target)
{
    int sp, dp;
      if ( target == me ) target = offensive_target(me);
        if( environment(me)->query("no_suck") )
        return notify_fail("���ﲻ����ȡ����\n");
    if( !objectp(target) || target->query("id") == "mu ren" )
        return notify_fail("��Ҫ��ȡ˭�ľ���\n");
    if ( me->query_temp("sucked") )
        return notify_fail("��ո���ȡ������\n");
    if( objectp(me->query_temp("weapon")) )
        return notify_fail("�������ֲ���ʩ�û��������˾�����\n");
    if( (int)me->query_skill("huagong-dafa",1) < 45 )
        return notify_fail("��Ļ����󷨹���������������ȡ�Է��ľ���\n");
    if( (int)me->query("neili",1) < 10 )
        return notify_fail("�����������������ʹ�û����󷨡�\n");
        if( (int)target->query("jing") < 45 || !living(target) )
        return notify_fail( target->name() +
            "�Ѿ������ɢ�����Ѿ��޷�����������ȡ�����ˣ�\n");
    message_vision( HIR "$NͻȻ���ص�һЦ��˫��һǰһ���׼$n��̫��Ѩ���˹�����\n\n" NOR, me, target );
        if ( living(target) )
           { if( !target->is_killing(me) ) target->kill_ob(me); }
        sp = me->query_skill("force") + me->query_skill("dodge") + me->query_skill("zhaixinggong",1)/2;
        dp = target->query_skill("force") + target->query_skill("dodge");
    me->set_temp("sucked", 1);      
        if (( random(sp) > random(dp) ) )
    {
        tell_object(target, HIR "���;������������̰��ʹ����־������ͷ����һƬ�հף�\n" NOR);
        tell_object(me, HIG "�����" + target->name() + "�ľ���������ԴԴ���������˽�����\n" NOR);
        target->receive_damage("jing", (int)me->query_skill("huagong-dafa", 1) );
        me->add("jing", (int)me->query_skill("huagong-dafa", 1) );
        me->add("eff_jing", (int)(me->query_skill("huagong-dafa", 1)*2/3) );
            if ( me->query("eff_jing") > me->query("max_jing") )
                 me->set("eff_jing", me->query("max_jing"));
        if( target->query("combat_exp") >= me->query("combat_exp") ) {      
            if( (int)me->query("potential") - (int)me->query("learned_points") < 100 )
                me->add("potential", 1);
        }
                me->start_busy(3);
                target->start_busy(random(3));
        me->add("neili", -5);
        call_out("del_sucked", 2, me);
    }
    else
    {   
        message_vision(HIY "����$p������$P����ͼ����������˿�ȥ��\n" NOR, me, target);
                me->start_busy(3);
        call_out("del_sucked", 4, me);
    }
    return 1;
}
void del_sucked(object me)
{
    if ( me && me->query_temp("sucked") )
    me->delete_temp("sucked");
}
