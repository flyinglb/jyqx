// lingboweibu.c 凌波微步
#include <ansi.h>
inherit SKILL;
string *dodge_msg = ({
        "只见$n施展凌波微步，神光离合，乍阴乍阳，动无常则，进止难期。\n",
        "只见$n施展凌波微步，步法轻盈，仿佛轻云之蔽月，不知怎的就到了数丈之外。\n",
        "$n的身影飘飘兮若流风之回雪，施展的正是凌波微步，$N连$n的衣角都沾不到。\n",
        "但见$n施展凌波微步，左一转，右一斜，就已经绕到了$N的身後。\n",
        "可是$n施展凌波微步，只是轻描淡写地向旁踏出一步，就巧妙地避开了$N的攻势。\n",
        "只见$n身影滴溜溜地一转，体迅飞鸟，飘忽若神，施展的正是凌波微步。\n",
        "$N只觉得眼前一花，头脑发昏，只觉得四面都是$n的身影！\n",
        "$n左脚轻轻地踏出一步，施展凌波微步，若往若返，把$N牵得团团乱转。\n",
});
int valid_enable(string usage) 
{ 
    return (usage == "dodge"); 
}
int practice_level(){   return 101;  }
int valid_learn(object me)
{
        if( (int)me->query("max_neili") < 500 )
                return notify_fail("你的内力修为不够，无法研习高深的步法。\n");
        if( (int)me->query_skill("force") < 80 )
                return notify_fail("你的内功火候不够，无法研习高深的步法。\n");
    if (me->query_skill("dodge", 1) <=me->query_skill("lingboweibu", 1))
        return notify_fail("你的基础不够，无法领会更高深的技巧。\n");
    return 1;
}
string query_dodge_msg(string limb,object me)
{
        me->set_temp("fight/dodge",me->query_skill("shaolin-shenfa",1)/3);
        return dodge_msg[random(sizeof(dodge_msg))];
}
int practice_skill(object me)
{
        if( (int)me->query("qi") < 40 )
                return notify_fail("你的体力太差了，不能练凌波微步。\n");
        me->receive_damage("qi", 30);
        if (me->query("neili")<1*me->query("max_neili"))
        me->add("neili",me->query_skill("dodge")/30);
        else
        return notify_fail(YEL"你只觉得胸口郁闷无比，几乎喘不过气来！\n"NOR);
        return 1;
 }
string perform_action_file(string action)
{
    return __DIR__"lingboweibu/" + action;
}

