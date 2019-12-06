// tanzhi.c 弹指神通
inherit SKILL;
mapping *action = ({
([  "action" : "$N右指划了个半圈，一式「"+BLK+"划天裂地"+NOR+"」自上而下划向$n的全身",
    "force" : 320,
    "lvl" : 0,
    "skill_name" : BLK "划天裂地" NOR,
    "damage_type" : "刺伤"
]),
([  "action" : "$N左掌护胸，一招「"+RED+"我心悠悠"+NOR+"」，右指欲举无力指向$n的额头",
    "force" : 280,
    "lvl" : 0,
    "skill_name" : RED "我心悠悠" NOR,
    "damage_type" : "刺伤"
]),
([  "action" : "$N双手齐出，一式「"+GRN+"千夫所指"+NOR+"」，疾指向$n的$l",
    "force" : 190,
    "lvl" : 0,
    "skill_name" : GRN "千夫所指" NOR,
    "damage_type" : "刺伤"
]),
([  "action" : "$N仰天一叹，一招「"+YEL+"弹指人生"+NOR+"」，双手幻出重重指影，点向$n的$l",
    "force" : 380,
    "lvl" : 50,
    "skill_name" : YEL "弹指人生" NOR,
    "damage_type" : "刺伤"
]),
([  "action" : "$N一式「"+HIC+"笑指天南"+NOR+"」，左掌蓄式，右指弹出一缕指风点向$n的$l",
    "force" : 240,
    "lvl" : 10,
    "skill_name" : HIC "笑指天南" NOR,
    "damage_type" : "刺伤"
]),
([  "action" : "$N用出「"+HIW+"擎天一指"+NOR+"」，蓄集全身力气，一指点向$n的$l",
    "force" : 420,
    "lvl" : 80,
    "skill_name" : HIW "擎天一指" NOR,
    "damage_type" : "刺伤"
]),
});
  int valid_enable(string usage) { return usage=="finger" || usage=="parry"; }
int practice_level(){   return 80;  }
int valid_combine(string combo) { return combo=="lanhua-shuo"; }
int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("练弹指神通必须空手。\n");
    if ((int)me->query_skill("bibo-shengong", 1) < 20)
        return notify_fail("你的碧波神功火候不够，无法学弹指神通。\n");
    if ((int)me->query("max_neili") < 100)
        return notify_fail("你的内力太弱，无法练弹指神通。\n");
    if (me->query_skill("finger", 1) <=me->query_skill("tanzhi-shentong", 1))
        return notify_fail("你的基础不够，无法领会更高深的技巧。\n");
    return 1;
}
string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}
mapping query_action(object me, object weapon)
{
    mapping a_action;
    int i, level;
    level   = (int) me->query_skill("tanzhi-shentong", 1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action = action[NewRandom(i, 20, level/5)];
                        break;
                }
    a_action["dodge"]  = 0-level/3;
    a_action["parry"]  = 0-level*3;
    a_action["attack"]  = level/3;
    a_action["damage"] = level*2;
    return a_action;

}

int practice_skill(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("练弹指神通必须空手。\n");
    if ((int)me->query("qi") < 30)
        return notify_fail("你的体力不够，休息一下再练吧。\n");
    if ((int)me->query("neili") < 20)
        return notify_fail("你的内力不够练弹指神通。\n");
    me->receive_damage("qi", 30);
    me->add("neili", -10);
    return 1;
}
string perform_action_file(string action)
{
    return __DIR__"tanzhi-shentong/" + action;
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
    if( damage_bonus < 100 ) return 0;
    if( random(me->query_str()*2) > victim->query_str() && me->query("neili")>100) {
        me->add("neili",-100);
        victim->receive_wound("qi", (damage_bonus) / 5 , me);
        return RED "丝丝一声轻响，你听到竟似是骨裂的声音！\n" NOR;
    }
}
