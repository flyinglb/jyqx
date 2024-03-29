#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit F_SSERVER;
 
void do_attack(object me,object target,object weapon)
{
    int i;
    if (!me) return;
    me->delete_temp("perform");
    if (!living(me) || !target ) return;
    if (weapon == me->query_temp("secondary_weapon") )
    me->set_temp("secondly_weapon",1);
    if (!weapon->query("equipped")){ me->start_busy(1); return; }
    if (environment(me)!=environment(target)) return;
    for(i = 0; i < 3; i++)
        if (me->is_fighting(target) && target->is_fighting(me) && target->query("eff_qi")>0)
        {
            me->set_temp("action_msg","紧接着");
            if (!weapon->query("equipped")) { me->start_busy(1); return; }
            if (me->query_skill_mapped("blade")!="wuhu-duanmendao") {me->start_busy(1); return; }
            COMBAT_D->do_attack(me, target, weapon, 0);
        }
        else break;
    me->delete_temp("secondly_weapon");
}

int perform(object me, object target)
{
    object weapon;
    string msg;

    if( !target ) target = offensive_target(me);
    if( !target ||  !target->is_character() ||  !me->is_fighting(target) )
        return notify_fail("五虎断门刀「断」字决只能在战斗中使用。\n");
    if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "blade")
    if (!objectp(weapon = me->query_temp("secondary_weapon")) || (string)weapon->query("skill_type") != "blade")
        return notify_fail("你使用的武器不对。\n");
    if( (int)me->query_skill("blade") < 60 || me->query_skill_mapped("blade") != "wuhu-duanmendao")
        return notify_fail("你的「五虎断门刀」还不到家，无法使用「断」字决！\n");

    if (!me->visible(target))    return notify_fail("你看不到"+target->name()+"。\n");
    if (me->query_temp("perform"))  return notify_fail("你上一个招式还没完成!\n");
    if (me->query("neili")<200 )   return notify_fail("你的内力不足!\n");

    msg = HIY "$N猛然伏地，使出地堂刀断字决，顿时一片白光直向前滚去！\n" NOR;

    if( !living(target) || random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 )
    {
        me->start_call_out( (: call_other, __FILE__, "do_attack", me,target,weapon :), 0);
        if (me->query("neili")<150) me->set("neili",0);
        else me->add("neili", -150);
        me->set_temp("perform",1);
    }
    else
    {
        msg += HIY"可是$p"+ HIY +"看破了$P的企图，并没有上当。\n" NOR;
        me->start_busy(2);
    }
    message_vision(msg, me, target);
    return 1;
}



