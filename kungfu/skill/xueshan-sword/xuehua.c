
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
 
int perform(object me, object target)
{
        object weapon, ob;
        string msg;
//        int count;
        if( !target ) target = offensive_target(me);
 
        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("「"HIW"雪花六出"NOR"」只能在战斗中使用。\n");
 
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail(" 你使用的武器不对\n");

        if( (int)me->query("neili") < 150 )
                return notify_fail("你的真气不够！\n");

        if( (int)me->query_skill("bingxue-xinfa",1) < 50 )
                return notify_fail("你的冰雪心法修为还不够！\n");

        if( (int)me->query_skill("sword",1) < 50 ||
            me->query_skill_mapped("sword") != "xueshan-sword" || 
            me->query_skill("xueshan-sword",1) < 50)
                return notify_fail("你的雪山剑法修为不够，无法使用「雪花六出」！\n");

        msg = HIY "$N一抖手中长剑，一式"HIW"「雪花六出」"NOR+HIY"，连续刺出六剑，剑剑快如流星，\n幻成雪花六点，带起一阵寒飚向前疾飘而去。\n" NOR;
        message_vision(msg, me);

        me->add_temp("apply/attack", 200);
        me->clean_up_enemy();
        ob = me->select_opponent();

        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);

        me->add("neili", -100);
        me->start_busy(2+random(1));

        me->add_temp("apply/attack", -200);
        if(!ob->is_fighting(me)) ob->fight_ob(me);
        return 1;
}

