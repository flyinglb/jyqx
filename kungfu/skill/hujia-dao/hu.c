// HU.c 飞狐毕现
// 
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
 
int perform(object me, object target)
{
        object weapon, ob;
//        string msg, string1;
        string msg;
//        int count;
 
        if( !target ) target = offensive_target(me);

        if((int)me->query_str() < 30)
                return notify_fail("这项绝技最讲求臂力，你还不够呢!\n");

        if( !me->is_fighting() )
                return notify_fail("「飞狐毕现」只能在战斗中使用。\n");

        if( target->is_busy() )
                return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧ⅵ\n");
 
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "blade")
                return notify_fail("「飞狐毕现」必须拿着刀才能使出！\n");

        if( (int)me->query("neili") < 200 )
                return notify_fail("你的真气不够！\n");

        if( (int)me->query_skill("blade") < 50 ||
            me->query_skill_mapped("blade") != "hujia-dao")
                return notify_fail("你的胡家刀法还不到家，无法使用飞狐毕现！\n");

    if( !living(target) || random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 )
    {
        msg = HBRED "$N使出胡家秘技「飞狐毕现」，刀法陡然加快！\n" NOR;
        message_vision(msg, me);

        me->clean_up_enemy();
        ob = me->select_opponent();

        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);

        me->add("neili", -200);
        me->start_busy(3);
        ob->start_busy(random(5));
    }
    else
    {
       msg = HIY  "可是$p"+ HIY +"看破了$P的企图，并没有上当。\n" NOR;
         me->start_busy(3);
    }

        return 1;
}

