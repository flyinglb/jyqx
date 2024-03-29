// tianwai.c 天外清音

#include <ansi.h>

inherit F_SSERVER;

int perform(object me)
{
        string msg;
        object weapon, target;
//        int skill, ap, dp, neili_wound, qi_wound;
        int skill, ap, dp, qi_wound;

        me->clean_up_enemy();
        target = me->select_opponent();

        skill = me->query_skill("yuxiao-jian",1);

        if( !(me->is_fighting() ))
            return notify_fail("「天外清音」只能对战斗中的对手使用。\n");

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
            return notify_fail("你使用的武器不对。\n");

        if( me->query_skill("bibo-shengong",1) < 120)
            return notify_fail("你的碧波神功等级不够, 不能使用「天外清音」！\n");

        if( skill < 90)
            return notify_fail("你的玉箫剑法等级不够, 不能使用「天外清音」！\n");

        if( me->query("neili") < 250 )
            return notify_fail("你的内力不够，无法运用「天外清音」！\n");

        msg = HIC 
"$N一声清啸，剑发琴音，深吸一口气，剑附内力，一式「天外清音」，\n"+weapon->name()
+HIC+"闪动不止，剑影如夜幕般扑向$n。\n";
        message_vision(msg, me, target);

        ap = me->query_skill("sword") + skill;
        dp = target->query_skill("force") / 4;
        if( dp < 1 )
            dp = 1;
        if( random(ap) > dp )
        {
            if(userp(me))
                 me->add("neili",-150);
            msg = "$n顿时觉得眼前金光乱闪动，双耳嗡嗡内鸣，不知那里一阵刺痛如针扎一般！\n" NOR;
           qi_wound = (int)me->query_skill("yuxiao-jian",1)+(int)me->query_skill("sword",1)+0.5*(int)me->query_skill("music",1);
            qi_wound = qi_wound/2 + random(qi_wound);
            if(qi_wound > target->query("qi"))
                 qi_wound = target->query("qi");

            target->receive_damage("qi", qi_wound);
            target->receive_wound("qi", qi_wound/2);
            target->start_busy(2);
            me->start_busy(2);
        }
        else
        {
            if(userp(me))
                 me->add("neili",-100);
            msg = "可是$n宁心静气，随手挥洒，将$N的招数撇在一边。\n"NOR;
            me->start_busy(random(3));
        }
        message_vision(msg, me, target);
        if(!target->is_fighting(me)) target->fight_ob(me);
        return 1;
}
