// maxsuck.c

#include <ansi.h>

inherit F_SSERVER;
int exert(object me, object target)
{
        int sp, dp;
        int my_max, tg_max;

       if ( target == me ) target = offensive_target(me);

        if( !objectp(target) || target->query("id") == "mu ren" )
                return notify_fail("��Ҫ��ȡ˭�ĵ�Ԫ��\n");

        my_max = me->query("max_neili");
        tg_max = target->query("max_neili");

        if ( me->query_temp("sucked") )
                return notify_fail("��ո���ȡ����Ԫ��\n");

        if( environment(me)->query("no_suck") )
        return notify_fail("���ﲻ����ȡ��Ԫ��\n");
        if( objectp(me->query_temp("weapon")) )
                return notify_fail("�������ֲ���ʩ�û��������˵�Ԫ��\n");

//        if( !me->is_fighting() || !target->is_fighting())

        if( (int)me->query_skill("huagong-dafa",1) < 90 )
                return notify_fail("��Ļ����󷨹���������������ȡ�Է��ĵ�Ԫ���\n");

        if( (int)me->query("neili",1) < 20 )
                return notify_fail("�����������������ʹ�û����󷨡�\n");

        if( (int)target->query("max_neili") < 100 )
                return notify_fail( target->name() +
                        "��Ԫ��ɢ������δ�ۣ����޷�����������ȡ�κζ�����\n");

        if( (int)target->query("max_neili") < (int)me->query("max_neili")/10 )
                return notify_fail( target->name() +
                        "���ڹ���ΪԶ�����㣬���޷�����������ȡ��Ԫ��\n");

        message_vision(
                HIR "$Nȫ��ǽڱ��죬˫�۱������ߣ���Ե�͵���$n������������ȥ��\n\n" NOR,
                me, target );

        if ( living(target) )
           { if( !target->is_killing(me) ) target->kill_ob(me); }

        sp = me->query_skill("force") + me->query_skill("dodge") + me->query_skill("zhaixinggong",1)/2;
        dp = target->query_skill("force") + target->query_skill("dodge");

        me->set_temp("sucked", 1);              

        if (( random(sp) > random(dp) ) || !living(target) )
        {
                tell_object(target, HIR "��ֻ���춥���ѣ�ȫ�������Զ���������ѩ����ʧ����Ӱ���٣�\n" NOR);
                tell_object(me, HIG "�����" + target->name() + "�ĵ�Ԫ������ԴԴ���������˽�����\n" NOR);

                target->add("max_neili",  -1*(1+(me->query_skill("huagong-dafa", 1)-90)/5) );
                me->add("max_neili",       1*(1+(me->query_skill("huagong-dafa", 1)-90)/5) );
                if ( target->query("max_neili") <1) target->set("max_neili",0);

                if( (int)me->query("potential") - (int)me->query("learned_points") < 90 )
                        me->add("potential",  2);
                me->add("combat_exp", 10);

                me->start_busy(7);
                target->start_busy(random(7));
                me->add("neili", -10);

                call_out("del_sucked", 10, me);
        }
        else
        {       
                message_vision(HIY "����$p������$P����ͼ����������˿�ȥ��\n" NOR, me, target);
                me->start_busy(7);
                call_out("del_sucked", 20, me);
        }

        return 1;
}

void del_sucked(object me)
{
        if ( me->query_temp("sucked") )
        me->delete_temp("sucked");
}

