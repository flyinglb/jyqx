// huayu.c

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        int skill, i;
        string msg;
        object weapon, *ob;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("满天花雨只能在战斗中使用。\n");

        if (!objectp(weapon = me->query_temp("weapon"))
	     || (string)weapon->query("skill_type") != "throwing")
		return notify_fail("你使用的武器不对。\n");

        if( (int)me->query_skill("feixing-shu", 1) < 100 )
                return notify_fail("你的飞星术不够娴熟，不会使用满天花雨。\n");
        if( (int)me->query_skill("huagong-dafa", 1) < 100 )
                return notify_fail("你的化功大法不够娴熟，不能使用满天花雨。\n");

        if( (int)me->query("neili") < 300 )
                return notify_fail("你内力不够了。\n");

        skill = me->query_skill("feixing-shu", 1);

        me->add("neili", -200);
        target->receive_damage("qi", (int)skill/ 3);

        msg="只听一股劲风从$N的右侧发出，$N手中的"+weapon->name()+"如烟雨般向$n笼罩过去！\n";

        me->start_busy(2);
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2)
        {
                msg += "结果$p被$P攻了个措手不及！\n" NOR;
                target->receive_wound("qi", random(skill)*2);
                target->start_busy(random(3));
        } else {
                msg += "可是$p躲过了$P的最后一击。\n" NOR;
        }
        message_vision(msg, me, target);
        ob = all_inventory(me);         //use out all throwing
        for(i=sizeof(ob)-1; i>=0; i--) {
        if( (string)ob[i]->query("equipped")!="wielded" ) continue;
        ob[i]->unequip();
                  ob[i]->move(environment(me));
        }
                  me->reset_action();
        return 1;
}

