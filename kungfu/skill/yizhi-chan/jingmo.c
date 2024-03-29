// jingmo.c 一指禅 「惊魔一指」
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
    string msg;
    if( !target ) target = offensive_target(me);
    if( !target
    ||  !target->is_character()
    ||  !me->is_fighting(target) )
        return notify_fail("牵制攻击只能对战斗中的对手使用。\n");
    if( objectp(me->query_temp("weapon")) && objectp(me->query_temp("secondary_weapon")) )
        return notify_fail("你必须空出一只手来使用「惊魔一指」绝招！\n");     

    if((int)me->query_str() < 30)
        return notify_fail("你臂力不够,不能使用这一绝技!\n");
    if((int)me->query_skill("hunyuan-yiqi",1) < 100 )
    if((int)me->query_skill("yijing-force",1) < 100)
        return notify_fail("你混元一气功的功力不够不能使用惊魔一指!\n");
    if((int)me->query_skill("yizhi-chan",1) < 150)
        return notify_fail("你的指法修为不够,目前还不能使用惊魔一指绝技!\n");
    if((int)me->query("neili") < 800)
        return notify_fail("你内力现在不够, 不能使用惊魔一指! \n");
    if (!me->visible(target))    return notify_fail("你看不到"+target->name()+"。\n");
    if( target->is_busy() )
        return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧ⅵ\n");
    msg = HIY "$N使出一阳指绝技「惊魔一指」，罩住了$n的全身要穴, 使$n动弹不得。\n";
    if( random(COMBAT_D->skill_power(me, "unarmed", SKILL_USAGE_ATTACK)) > COMBAT_D->skill_power(target,"dodge", SKILL_USAGE_DEFENSE) / 3 ) {
        msg += "结果$p被$P攻了个措手不及！\n" NOR;
        target->start_busy( (int)me->query_skill("yizhi-chan",1) / 100 + 2);
        me->add("neili", -150);
    } else {
        msg += HIG "可是$p看破了$P的企图，并没有上当。\n" NOR;
        me->start_busy(4);
    }
    message_vision(msg, me, target);
    return 1;
}
