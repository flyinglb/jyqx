// duopo.c  金蛇剑法  (夺魄)
//
#include <ansi.h>
inherit F_SSERVER;
void end(object,int);
int perform(object me, object target)
{
        int damage;
        string msg;
        if( !target ) target = offensive_target(me);
        if( !target || !target->is_character() )
                return notify_fail("夺魄只能对同地方的对手使用。\n");
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("夺魄只能对战斗中的对手使用。\n");
        if( (int)me->query_skill("jinshe-jian", 1) < 100 )
                return notify_fail("你的金蛇剑法不够娴熟，不会使用「夺魄」。\n");
        if( (int)me->query("neili", 1) < 200 )
                return notify_fail("你现在内力太弱，不能使出夺魄。\n");
        if( target->query_temp("sword")==1)
                return notify_fail(target->query("name")+"正在魂飞魄散间，快放手攻击啊! \n");
        msg = HIW "$N突然眼中金芒大盛，一股寒意破空直袭$n。\n"NOR;
        me->add("neili", -400);
        me->start_busy(1);
        if(random(me->query("combat_exp"))>(int)target->query("combat_exp")/2)
        {
                msg += WHT"$p被吓得魂飞魄散，只见对方攻势大盛，越战越勇。\n"NOR;
                target->start_busy(3);
                me->add("neili",-100);
                damage=me->query_skill("jinshe-jian",1);
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
                msg += HIY"$p沉着应战，没有受到“夺魄”攻击的影响！\n"NOR;
        }
        message_vision(msg, me, target);
        return 1;
}

void end(object target,int damage)
{
  if( !objectp(target) ) return;
  target->delete_temp("sword");
  target->add_temp("apply/attack",0-damage);
  target->add_temp("apply/defense",0-damage);
  message_vision(RED"$N终于从夺魄的阴影里恢复了出来。\n"NOR,target);
}


