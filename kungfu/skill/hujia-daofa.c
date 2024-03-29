//
// hujia-daofa.c 
// Designed by secret(秘密)
//
inherit SKILL;
mapping *action = ({
([      "action" : "$N手中$w横推，一招「"+BLU+"推波助澜"+NOR+"」，由上至下向$nl砍去  ",
        "skill_name" : BLU "推波助澜" NOR,
        "force" : 80,
        "dodge" : -10,
        "parry" : 10,
        "lvl" : 0,
        "damage" : 25,
        "damage_type" : "割伤",
]),
([      "action" : "$N一招「"+RED+"沙鸥掠波"+NOR+"」，刀锋自下而上划了个半弧，$w一提一收，平刃挥向$n的颈部  ",
        "skill_name" : RED "沙鸥掠波" NOR,
        "force" : 100,
        "dodge" : 5,
        "parry" : 10,
        "lvl" : 8,
        "damage" : 30,
        "damage_type" : "割伤",
]),
([      "action" : "$N使出一招「"+BLU+"天设牢笼"+NOR+"」，将$w舞得如白雾一般压向$n ",
        "skill_name" : BLU "天设牢笼" NOR,
        "force" : 120,
        "dodge" : 10,
        "parry" : 10,
        "lvl" : 16,
        "damage" : 35,
        "damage_type" : "割伤",
]),
([      "action" : "$N一招「"+YEL+"闭门铁扇"+NOR+"」，$w缓缓的斜着向$n推去 ",
        "skill_name" : "闭门铁扇",
        "force" : 150,
        "dodge" : 5,
        "parry" : 10,
        "lvl" : 24,
        "damage" : 40,
        "damage_type" : "割伤",
]),
([      "action" : "$N手拖$w，转身跃起，一招「"+MAG+"翼德闯帐"+NOR+"」，一道白光射向$n的胸口 ",
        "skill_name" : MAG "翼德闯帐" NOR,
        "force" : 200,
        "dodge" : -5,
        "parry" : 5,
        "lvl" : 32,
        "damage" : 45,
        "damage_type" : "割伤",
]),
([      "action" : "$N挥舞$w，使出一招「"+HIW+"白鹤舒翅"+NOR+"」，上劈下撩，左挡右开，齐齐罩向$n  ",
        "skill_name" : HIW "白鹤舒翅" NOR,
        "force" : 230,
        "dodge" : 10,
        "parry" : 5,
        "lvl" : 40,
        "damage" : 50,
        "damage_type" : "割伤",
]),
([      "action" : "$N一招「"+RED+"春风送暖"+NOR+"」，左脚跃步落地，$w顺势往前，挟风声劈向$n的$l  ",
        "skill_name" : RED "春风送暖" NOR,
        "force" : 300,
        "dodge" : 5,
        "parry" : 10,
        "lvl" : 48,
        "damage" : 60,
        "damage_type" : "割伤",
]),
([      "action" : "$N 忽的使一招「"+MAG+"八方藏刀"+NOR+"」，顿时剑光中无数朵刀花从四面八方涌向$n全身  ",
        "skill_name" : MAG "八方藏刀" NOR,
        "force" : 320,
        "dodge" : 10,
        "parry" : 20,
        "lvl" : 56,
        "damage" : 70,
        "damage_type" : "割伤",
]),
});

int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }
//int valid_combine(string combo) { return combo=="mingwang-jian"; }
int practice_level(){   return 56;  }
int valid_learn(object me)
{
    if ((int)me->query("max_neili") < 1200)
        return notify_fail("你的内力不够。\n");
    if ((int)me->query_skill("hunyuan-yiqi", 1) >= 20 ||
        (int)me->query_skill("force", 1) >= 20)
        return 1;
    else if ((int)me->query_skill("hunyuan-yiqi", 1) < 20)
        return notify_fail("你的混元一气功火候太浅。\n");
    else if ((int)me->query_skill("force", 1) < 20)
        return notify_fail("你的基本内功火候太浅。\n");
    if (me->query_skill("blade", 1) <=me->query_skill("hujian-daofa", 1))
        return notify_fail("你的基础不够，无法领会更高深的技巧。\n");
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
        int i, level;
    level   = (int) me->query_skill("hujia-daofa",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}
int practice_skill(object me)
{
    object weapon;
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "blade")
        return notify_fail("你使用的武器不对。\n");
    if ((int)me->query("qi") < 50)
        return notify_fail("你的体力不够，练不了胡家刀法。\n");
    me->receive_damage("qi", 30);
    return 1;
}
