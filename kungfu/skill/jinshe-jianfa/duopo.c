// duopo.c  ���߽���  (����)
//create bye enter
#include <ansi.h>
inherit F_SSERVER;
void end(object,int);
int perform(object me, object target)
{
        int damage;
        string msg;
        if( !target ) target = offensive_target(me);
        if( !target || !target->is_character() )
                return notify_fail("����ֻ�ܶ�ͬ�ط��Ķ���ʹ�á�\n");
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("����ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        if( (int)me->query_skill("jinshe-jianfa", 1) < 100 )
                return notify_fail("��Ľ��߽���������죬����ʹ�á����ǡ���\n");
        if( (int)me->query("neili", 1) < 200 )
                return notify_fail("����������̫��������ʹ�����ǡ�\n");
        if( target->query_temp("sword")==1)
                return notify_fail(target->query("name")+"���ڻ����ɢ�䣬����ֹ�����! \n");
        msg = HIW "$NͻȻ���н�â��ʢ��һ�ɺ����ƿ�ֱϮ$n��\n"NOR;
        me->add("neili", -400);
        me->start_busy(1);
        if(random(me->query("combat_exp"))>(int)target->query("combat_exp")/2)
        {
                msg += WHT"$p���ŵû����ɢ��ֻ���Է����ƴ�ʢ��ԽսԽ�¡�\n"NOR;
                target->start_busy(3);
                me->add("neili",-100);
                damage=me->query_skill("jinshe-jianfa",1);
                damage=0-damage/8-random(damage/8);
                if(!target->query_temp("apply/attack"))
                    target->set_temp("apply/attack",damage);
                else
                    target->add_temp("apply/attack",damage);
                if(!target->query_temp("apply/defense"))
                    target->set_temp("apply/defense",damage);
                else
                    target->add_temp("apply/defense",damage);
                target->set_temp("sword",1);
                call_out("end",30,target,damage);
        }
        else
        {
                msg += HIY"$p����Ӧս��û���ܵ������ǡ�������Ӱ�죡\n"NOR;
        }
        message_vision(msg, me, target);
        return 1;
}

void end(object target,int damage)
{
  target->delete_temp("sword");
  target->add_temp("apply/attack",0-damage);
  target->add_temp("apply/defense",0-damage);
  message_vision(RED"$N���ڴӶ��ǵ���Ӱ��ָ��˳�����\n"NOR,target);
}

