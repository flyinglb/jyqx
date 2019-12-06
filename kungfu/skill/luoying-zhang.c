// luoying.c
inherit SKILL;
mapping *action = ({
    ([  "action":       "$N使一招「"+RED+"落英缤纷"+NOR+"」，双手飘移不定击向$n$l",
        "dodge": 30,
        "parry": 20,
        "force": 120,
        "damage_type": "瘀伤"
    ]),
    ([  "action":       "$N倏忽欺至$n身前，一招「"+MAG+"人面桃花"+NOR+"」直拍$n的$l",
        "dodge": -20,
        "parry": -20,
        "force": 160,
        "damage_type": "瘀伤"
    ]),
 ([  "action":"$N身形绕$n一转，一招「"+HIY+"急风骤雨"+NOR+"」向$n$l接连出掌",
        "dodge":  25,
        "parry":  20,
        "force": 200,
        "damage_type": "瘀伤"
    ]),
    ([  "action":       "$N身形拔起，在半空一招「"+HIC+"江城飞花"+NOR+"」右掌猛击$n的$l",
        "dodge": -30,
        "parry": -30,
        "force": 240,
        "damage_type": "瘀伤"
    ]),
    ([  "action":       "$N使一招「"+HIM+"万花齐落"+NOR+"」，纵起丈余直击$n的$l",
        "dodge": -20,
        "parry":  40,
        "force": 280,
        "damage_type": "瘀伤"
    ]),
    ([  "action":       "$N一声大喝使出「"+HIM+"漫天花雨"+NOR+"」，幻出满天掌影，掌掌不离$n的$l",
        "dodge":  40,
        "force": 340,
        "damage_type": "瘀伤"
    ]),
});
  int valid_enable(string usage) { return usage=="strike" ||  usage=="parry"; }
int practice_level(){   return 60;  }
int valid_combine(string combo) { return combo=="xuanfeng-leg"; }
int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("练落英神剑掌必须空手。\n");
    if ((int)me->query("max_neili") < 100)
        return notify_fail("你的内力太弱，无法练落英神剑掌。\n");
    if (me->query_skill("strike", 1) <=me->query_skill("luoying-zhang", 1))
        return notify_fail("你的基础不够，无法领会更高深的技巧。\n");
    return 1;
}
mapping query_action(object me, object weapon)
{
    return action[random(sizeof(action))];
}
int practice_skill(object me)
{
    if ((int)me->query("qi") < 40)
        return notify_fail("你的体力太低了。\n");
    if ((int)me->query("neili") < 10)
        return notify_fail("你的内力不够了！休息一下再练吧。\n");
    me->receive_damage("qi", 30);
    me->add("neili", -5);
    return 1;
}
