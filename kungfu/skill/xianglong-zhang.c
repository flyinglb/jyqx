// xianglong-zhang.c 降龙十八掌
#include <combat.h>
inherit SKILL;
mapping *action = ({
([  "action": "$N使出「"+HIC+"突如其来"+NOR+"」，右掌从不可能的角度向$n的$l推出",
    "force": 130,
   "damage_type": "瘀伤"
]),
([  "action": "$N右掌一招「"+HIC+"见龙在田"+NOR+"」，迅捷无比地劈向$n的$l",
    "force": 150,
    "damage_type": "瘀伤"
]),
([  "action": "$N双掌施出一招「"+HIC+"鸿渐于陆"+NOR+"」，隐隐带着风声拍向$n的$l",
    "force": 170,
    "damage_type": "瘀伤"
]),
([  "action": "$N身形滑动，双掌使一招「"+HIC+"双龙取水"+NOR+"」一前一后按向$n的$l",
    "force": 190,
    "damage_type": "瘀伤"
]),
([  "action": "$N突然身形飞起，双掌居高临下一招「"+HIC+"飞龙在天"+NOR+"」拍向$n的$l",
    "force": 210,
    "damage_type": "瘀伤"
]),
([  "action": "$N左掌聚成拳状，右掌一招「"+RED+"潜龙勿用"+NOR+"」缓缓推向$n的$l",
    "force": 220,
    "damage_type": "瘀伤"
]),
([  "action": "$N使出「"+RED+"羝羊触蕃"+NOR+"」，双掌由下往上击向$n的$l",
    "force": 230,
    "damage_type": "瘀伤"
]),
([  "action": "$N使出「"+RED+"密云不雨"+NOR+"」，左掌封住$n的退路，右掌斜斜地劈向$l",
    "force": 240,
    "damage_type": "瘀伤"
]),
([  "action": "$N左掌护胸，右掌使一招「"+YEL+"神龙摆尾"+NOR+"」上下晃动着击向$n的$l",
    "force": 250,
    "damage_type": "瘀伤"
]),
([  "action": "$N使出「"+YEL+"或跃在渊"+NOR+"」，向$n的$l连拍数掌",
    "force": 260,
    "damage_type": "瘀伤"
]),
([  "action": "$N施出一招「"+YEL+"利涉大川"+NOR+"」，右掌插腰，左掌劈向$n的$l",
    "force": 270,
    "damage_type": "瘀伤"
]),
([  "action": "$N使出「"+CYN+"鱼跃于渊"+NOR+"」，身形飞起，双掌并在一起向$n的$l劈下",
    "force": 160,
    "damage_type": "瘀伤"
]),
([  "action": "$N双掌立起，使出「"+CYN+"时乘六龙"+NOR+"」向$n连砍六下",
    "force": 300,
    "damage_type": "瘀伤"
]),
([  "action": "$N大吼一声，双掌使出「"+CYN+"震惊百里"+NOR+"」，不顾一切般击向$n",
    "force": 330,
    "damage_type": "瘀伤"
]),
([  "action": "$N门户大开，一招「"+GRN+"履霜冰至"+NOR+"」向$n的$l劈去",
    "force": 350,
    "damage_type": "瘀伤"
]),
([  "action": "$N脚下一转，突然欺到$n身前，一招「"+HIM+"龙战于野"+NOR+"」拍向$n的$l",
    "force": 360,
    "damage_type": "瘀伤"
]),
([  "action": "$N使出「"+RED+"损则有孚"+NOR+"」，双掌软绵绵地拍向$n的$l",
    "force": 380,
    "damage_type": "瘀伤"
]),
});
int valid_enable(string usage) { return usage=="unarmed" ||  usage=="parry"; }
int practice_level(){   return 180;  }
int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("练降龙十八掌必须空手。\n");
   if ((int)me->query("max_neili")<500)
        return notify_fail("你的内力太弱，无法练降龙十八掌。\n");
    if (me->query_skill("unarmed", 1) <=me->query_skill("xianglong-zhang", 1))
        return notify_fail("你的基础不够，无法领会更高深的技巧。\n");
    return 1;
}
mapping query_action(object me, object weapon)
{
    mapping ran_action;
    int level = me->query_skill("xianglong-zhang",1);
        if (me->query_temp("sum_power"))
        return ([  "action": "$N双掌平平提到胸前，神色沉重的缓缓施出「"+RED+"亢龙有悔"+NOR+"」推向$n的$l",
                    "damage": level*6,
                    "attack": level*2,
                    "dodge": 0 - 5 * level,
                    "damage_type": "瘀伤",
                ]);
    else{
        ran_action=action[random(sizeof(action))];
        ran_action["dodge"]= 0 - level;
        ran_action["damage"]= level;
        ran_action["attack"]= level/2;
        }
    return ran_action;
}
int practice_skill(object me)
{
    if ((int)me->query("qi") < 300)
        return notify_fail("你的体力太低了。\n");
    if ((int)me->query("neili") < 2000)
        return notify_fail("你的内力不够练降龙十八掌。\n");
    me->receive_damage("qi", 60);
    me->add("neili", -30);
    return 1;
}
void do_interlink(object me, object victim)
{
    int skill_level=me->query_skill("xianglong-zhang",1);
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return;
        if (me->is_fighting(victim) && victim->is_fighting(me))
        if (random(skill_level)>200 && me->query("neili")>5000){
        me->add("neili",-random(4500)-500);
          me->set_temp("sum_power",1);
          message_vision(HIY+"\n$N深深吸了口气，大吼一声，把降龙十七掌的精华融于双掌之中，\n"
          +"刹那间只看到狂风大作，飞沙走石，天地为之变色....\n"+NOR,me);
          COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_REGULAR);
          me->delete_temp("sum_power");
        }  
}
string perform_action_file(string action)
{
    return __DIR__"xianglong-zhang/" + action;
}

