//痴情三圣剑之“三圣绝技”。
#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
        object weapon;
        int damage;        
        weapon = me->query_temp("weapon");
        if( !target ) target = offensive_target(me);
        if( !target || !me->is_fighting(target) )
                return notify_fail("「三圣绝技」只能在战斗中对对手使用。\n");
        if (!weapon || weapon->query("skill_type") != "sword")
                return notify_fail("你必须在使用剑时才能使出「三圣绝技」！\n");
        if( (int)me->query_skill("chiqing-jian", 1) < 120 )
                return notify_fail("你的痴情三圣剑还不够娴熟，使不出「三圣绝技」。\n");
        if( (int)me->query_skill("xuantian-force", 1) < 160 )
                return notify_fail("你的内功修为不够，使不出「三圣绝技」。\n");
        if( (int)me->query_skill("force") < 240 )
                return notify_fail("你的内功修为不够，使不出「三圣绝技」。\n");
        if( (int)me->query_skill("music",1) < 140 )
                return notify_fail("你的音乐修养不够，使不出「三圣绝技」。\n");
        if( (int)me->query_skill("chess",1) < 140 )
                return notify_fail("你的棋弈修养不够，使不出「三圣绝技」。\n");
        if( (int)me->query_str() < 30)
                return notify_fail("你的膂力还不够，使不出「三圣绝技」。\n");
        if( (int)me->query_dex() < 30)
                return notify_fail("你的身法还不够，使不出「三圣绝技」。\n");
        if( (int)me->query("max_neili") < 2000 )
                return notify_fail("你现在内力太弱，使不出「三圣绝技」。\n");      
        if( (int)me->query("neili") < 1000 )
                return notify_fail("你现在真气太弱，使不出「三圣绝技」。\n"); 
        if( (int)me->query("jingli") < 500 )
                return notify_fail("你现在体力太弱，使不出「三圣绝技」。\n"); 
 
        msg = HIC "$N右手长剑剑光跳跃，左手似乎在下棋，又似在抚琴……\n\n"NOR;
        msg += HIY"$n为其气势所迫，不由得将随音乐起舞，又意欲随弈道沉思……\n\n"NOR;
        msg += HIR"然则这剑光已经直刺$n前胸，轻盈快捷，无可比拟……！\n\n"NOR;
        if (random(me->query_skill("sword"))>(int)target->query_skill("parry")/2)
        {
//              target->start_busy(random(3));
                damage = (int)me->query_skill("chiqing-jian", 1);
                damage = damage +  0.5 * (int)me->query_skill("sword", 1);
                damage = damage +  0.25 * (int)me->query_skill("music", 1);
                damage = damage +  0.25 * (int)me->query_skill("chess", 1);
                target->receive_damage("qi", damage/2);
                target->receive_wound("qi", damage/3);
                target->receive_damage("jing", damage/2);
                target->receive_wound("jing", damage/3);
        msg += HIG"$n根本没法躲避，「三圣绝技」的上半部「剑发琴音」已经……\n\n"NOR;
        msg += HIM"笔直地刺在$n胸口！$n一仰头，胸口的鲜血随长剑溅出……\n\n"NOR;
                me->add("neili", -500);
                me->add("jingli", -250);
        } else
        {
        msg += HIB"可是$p轻转身形，伸出两指，正弹在$P的剑上，长剑夹带着……\n\n"NOR;
        msg += HIM"透骨的寒气从$p身侧划过，毫发无伤。\n\n"NOR;
                me->add("neili", -500);
                me->add("jingli", -250);
        }
        message_vision(msg, me, target);
	if(!target->is_fighting(me)) target->fight_ob(me);

        msg = HIW"\n$N上半个绝招尚未尽发，手中的"+weapon->name()+HIW"已然剑光闪过……\n\n"NOR;
	msg += HIY"分明是「三圣绝技」的下半部「剑入三劫」，一剑化为三剑，一剑快似一剑攻向$n！\n\n"NOR;
        message_vision(msg, me, target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
              me->add("neili",-500);
              me->add("jingli",-250);    

        me->start_busy(4);
        target->start_busy(4);
        return 1;
}
