// yinfengpai.c 三阴掌 「阴风拍」
#include <ansi.h>
inherit F_SSERVER;
int perform(object me, object target)
{
    int busy_time;
    if ( (time()-me->query_temp("perform_time"))<4)
        return notify_fail("你体内阴气已尽数散发了，现在无法再拍了。\n");
    if( !target ) target = offensive_target(me);
    if( !target ) return notify_fail("你想拍谁？\n");
    if( !target->is_character() || target->is_corpse() )
        return notify_fail("看清楚一点，那并不是活物。\n");

    if((int)me->query_str() < 25)
        return notify_fail("你臂力不够,无法拍击!\n");
    if((int)me->query_skill("xuantian-force",1) < 100 )
        return 
        notify_fail("你内功修为不够，不能使用阴风拍!\n");
 if((int)me->query_skill("unarmed") < 120 || me->query_skill("sanyin-unarmed",1) < 100 )
        return 
        notify_fail("你的拳脚修为不够,目前还不能使用阴风拍绝技!\n");
    if((int)me->query("neili") < 400)
        return notify_fail("你的内力不够, 不能使用阴风拍! \n");
    if( target->is_busy() )
        return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧，哈哈。\n");

    message("vision", HIB "你感觉四周的空气骤然变冷！\n\n" NOR, environment(me), ({me}) );
    tell_object(me, HIB "你使出阴风拍绝招，暗运内劲，一股寒气袭向"+target->name()+"的周身！\n\n" NOR);

    if( random(me->query_skill("unarmed")) > (int)target->query_skill("parry") / 3 )
    {
        tell_object(target, HIB "你突然间觉得全身冻僵了一般，动弹不得！\n" NOR);
        message("vision", HIB "只见"+target->name()+"突然间神色如堕冰窟，动弹不得！\n\n" NOR, environment(me), ({target}) );
        busy_time=random( (int)me->query_skill("sanyin-unarmed",1) / 20 )+1;
        target->start_busy( busy_time );
        me->add("neili", -100);
    }
    else
    {
    message("vision", HIB + target->name() + "突然觉得一股寒气迎面扑来，不及细想向侧面闪开。\n" NOR,environment(me),({target}));
    tell_object(target, HIB "你突然觉得有一股寒气迎面扑来，不及细想向侧面闪开。\n" NOR);
    message_vision(HIB "$n定睛细看原来是$N在暗自发力，怒道：这种左道功夫也来害我，看招！\n" NOR,me,target);
    target->fight_ob(me);
    me->fight_ob(target);
    me->start_busy(3);
    }
    me->set_temp("perform_time",time());
    return 1;
}

