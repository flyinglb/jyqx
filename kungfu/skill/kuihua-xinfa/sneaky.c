// kuihua-xinfa (protect)
#include <ansi.h>
void remove_effect(object me, int amount);
int exert(object me, object target)
{
    int skill;
    if( target != me ) 
        return notify_fail("葵花心法只能对自己使用。\n");
    if( (int)me->query("neili") < 1000  ) 
        return notify_fail("你的内力不够。\n");
    if ((int)me->query_temp("apply/shade_vision"))
        return notify_fail("你已经在运功中了。\n");
    skill = me->query_skill("kuihua-xinfa",1);
        if (skill<90) return notify_fail("你的葵花心法还不够娴熟。\n");
    message_vision( HIW "$N微一凝神，运起葵花心法，整个人如同被烟雾笼罩一般，漂忽不定。\n"
    "鬼魅至极。\n" NOR, me);
    me->add("neili",-300);
    me->set_temp("apply/shade_vision",1);
    me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill :), skill/2);
    if( me->is_fighting() ) me->start_busy(1);
    return 1;
}
void remove_effect(object me, int amount)
{
    if (!me)    return;
    me->delete_temp("apply/shade_vision");
    message_vision( BOLD "$N的葵花心法运行完毕，全身忽的一顿，现出整个身形。\n" NOR, me);
}
void reset() { }
int clean_up() { return 1; }

