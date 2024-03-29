// mie.c  回风拂柳剑法「灭剑」

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        int damage;
        string msg;
        object weapon;

        if (!target ) target = offensive_target(me);
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail(RED"开什么玩笑，没装备剑就想使「灭剑」？\n"NOR);
        if (!target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("「灭剑」只能对战斗中的对手使用。\n");
        if ((int)me->query_skill("huifeng-jian", 1) < 60 )
                return notify_fail(WHT"你的回风拂柳剑法不够娴熟，还使不出「灭剑」。\n"NOR);
        if ((int)me->query_skill("linji-zhuang", 1) < 60 )
                return notify_fail(RED"你的临济十二庄火候不够，「灭剑」不成招式。\n"NOR);
        if ((int)me->query("max_neili")<400)
                return notify_fail(RED"你的内力修为不足，无法运足「灭剑」的内力。\n"NOR);
        if ((int)me->query("neili")<200)
        {
               return notify_fail(HIC"你现在内力不够，没能将「灭剑」使完！\n"NOR);
        }
        msg = HIC "$N手中长剑剑芒跃动，剑光暴长，幻出死亡的色彩，剑尖渐\n"NOR;
        msg += HIC"渐逼近$n，$n看到漫天剑光，抽身后跃，只这一刹，漫天剑\n"NOR;
        msg += HIC"影化为一剑直刺$n前胸，快捷无伦，只有一剑！\n"NOR;
        if (random(me->query_skill("force"))>target->query_skill("force")/2|| 
           random(me->query("combat_exp"))>(int)target->query("combat_exp")/3)
        {
                me->start_busy(3);
                target->start_busy(random(2));
                damage = (int)me->query_skill("huifeng-jian", 1);
                damage = damage + random(damage);
                target->receive_damage("qi", damage/2);
                target->receive_wound("qi", damage/2);
                target->receive_damage("jing", damage/2);
                target->receive_wound("jing", damage/2);
        msg += HIC"$n根本没法躲避，一式「回风拂柳剑」的绝招「灭剑」端端正\n"NOR;
        msg += HIC"正扎进在$n胸口！$n一低头，看长剑自胸口拔出！\n"NOR;
                me->add("neili", -200);
        } else
        {
                me->start_busy(3);
        msg += HIY"可是$p轻轻一笑，侧身右转，伸出两指，正弹在$P的剑上，长\n"NOR;
        msg += HIY"剑在$p身侧划过，毫发无伤。\n"NOR;
                me->add("neili", -200);
        }
        message_vision(msg, me, target);
	if(!target->is_fighting(me)) target->fight_ob(me);
//	if(userp(target)) target->fight_ob(me);
//	else if( !target->is_killing(me) ) target->kill_ob(me);
        return 1;
}
