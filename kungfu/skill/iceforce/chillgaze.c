// chillgaze.c
#include <ansi.h>
inherit F_CLEAN_UP;
int exert(object me, object target)
{
//    object *ob;
    int skill, damage;
    if( !target || !target->is_character() || !me->is_fighting(target) )
        return notify_fail("一\n");
    skill = (int) this_player()->query_skill("force");
    this_player()->add("neili", -50);
    this_player()->receive_damage("jing", 20);
    message_vision(
        HIB "$N眼神忽然发出异光，双瞳犹如两把利刃般盯著$n！\n" NOR, this_player(), target);

    if( random(100)*target->query("combat_exp")/100 > (int)me->query("combat_exp") / 2 ) {
        message_vision("$N很快地转过头去，避开了$n的目光。\n", target, this_player());
        return 1;
    }
    damage = (int)me->query("force_factor") * 2 - target->query("max_force") / 15;
    if( damage < 1 ) {
        message_vision("但是$N对$n的注视视若无睹....。\n", target, this_player());
        return 1;
    }
    target->receive_damage("jing", damage);
    if( random(skill) > (int)target->query("dex") * 2 )
        target->receive_wound("jing", damage/2);
    message_vision("$N被$n的目光所摄，不自禁地打了个寒噤。\n", target, this_player());
    return 1;
}
