//
// xiangmo-chu.c 金刚降魔杵
//
inherit SKILL;
mapping *action = ({
([      "action" : "$N高举手中$w，使出一招「"+BLK+"金刚再世"+NOR+"」，直劈$n的$l  ",
        "skill_name" : BLK "金刚再世" NOR,
        "lvl" : 0,
        "damage_type" : "挫伤",
]),
([      "action" : "$N使出「"+YEL+"金刚伏魔"+NOR+"」，单手舞动$w，一伏身，$w横扫$n的下盘  ",
        "skill_name" : YEL "金刚伏魔" NOR,
        "lvl" : 8,
        "damage_type" : "挫伤",
]),
([      "action" : "$N反身仰面，使出一式「"+YEL+"金刚宣法"+NOR+"」，双手握$W，一棍直刺$n的$l  ",
        "skill_name" : YEL "金刚宣法" NOR,
        "lvl" : 16,
        "damage_type" : "挫伤",
]),
([      "action" : "$N使出一招「"+MAG+"引趣众生"+NOR+"」，双手举棍撩向$n的裆部  ",
        "skill_name" : MAG "引趣众生" NOR,
        "lvl" : 24,
        "damage_type" : "挫伤",
]),
([      "action" : "$N舞动手中$w，使出「"+HIR+"歌舞阎罗"+NOR+"」，顿时罩住$n的全身  ",
        "skill_name" : HIR "歌舞阎罗" NOR,
        "lvl" : 32,
        "damage_type" : "挫伤",
]),
([      "action" : "$N使出一招「"+RED+"浮游血海"+NOR+"」，全身贴地而飞，一棍直捣$n的$l  ",
        "skill_name" : RED "浮游血海" NOR,
        "lvl" : 40,
        "damage_type" : "挫伤",
]),
([      "action" : "$N使出一式「"+HIY+"驱鬼御魔"+NOR+"」，以棍支地，双足飞揣$n的面门  ",
        "skill_name" : HIY "驱鬼御魔" NOR,
        "lvl" : 48,
        "damage_type" : "挫伤",
]),
([      "action" : "$N运力于掌，使出「"+HIB+"荡魔除妖"+NOR+"」，飞身疾进，手中$w横扫$n的$l  ",
        "skill_name" : HIB "荡魔除妖" NOR,
        "lvl" : 56,
        "damage_type" : "挫伤",
]),
});
int valid_enable(string usage) { return usage == "staff" || usage == "parry"; }
int practice_level(){   return 56;  }
int valid_learn(object me)
{
    object weapon;
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "staff")
        return notify_fail("你使用的武器不对。\n");

    if ((int)me->query("max_neili") < 50)
        return notify_fail("你的内力不够。\n");
    if (me->query_skill("staff", 1) <=me->query_skill("xiangmo-chu", 1))
        return notify_fail("你的基础不够，无法领会更高深的技巧。\n");
    if ((int)me->query_skill("longxiang", 1) < 20)
        return notify_fail("你的龙象般若功火候太浅。\n");
    else if ((int)me->query_skill("xiaowuxiang", 1) < 20)
        return notify_fail("你的小无相功火候太浅。\n");
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
        level   = (int) me->query_skill("xiangmo-chu",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action=action[NewRandom(i, 20, level/5)];
                       break;
                 }
    a_action["dodge"]  = 0-level/3;
    a_action["parry"]  = 0-level;
    a_action["attack"]  = level/2;
    a_action["damage"] = level;
    return a_action;
}

int practice_skill(object me)
{
    object weapon;
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "staff")
        return notify_fail("你使用的武器不对。\n");
    if ((int)me->query("qi") < 50)
        return notify_fail("你的体力不够，练不了金刚降魔杵。\n");
    me->receive_damage("qi", 30);
    return 1;
}
