// tianyu-qijian.c 天羽奇剑
inherit SKILL;
mapping *action = ({
([  "action":"$N使一式「"+HIC+"海天一线"+NOR+"」，手中$w嗡嗡微振，幻成一条疾光刺向$n的$l",
    "force" : 180,
    "lvl" : 0,
    "skill_name" : BLK "海天一线" NOR,
    "damage_type":  "割伤"
]),
([  "action":"$N错步上前，使出「"+RED+"闪电惊虹"+NOR+"」，手中$w划出一道剑光劈向$n的$l",
    "force" : 210,
    "lvl" : 9,
    "skill_name" : RED "闪电惊虹" NOR,
    "damage_type":  "割伤"
]),
([  "action":"$N手中$w一抖，一招「"+GRN+"日在九天"+NOR+"」，斜斜一剑反腕撩出，攻向$n的$l",
    "force" : 240,
    "lvl" : 18,
    "skill_name" : GRN "日在九天" NOR,
    "damage_type":  "割伤"
]),
([  "action":"$N手中剑锵啷啷长吟一声，一式「"+BLU+"咫尺天涯"+NOR+"」，一道剑光飞向$n的$l",
    "force" : 270,
    "lvl" : 27,
    "skill_name" : BLU "咫尺天涯" NOR,
    "damage_type":  "刺伤"
]),
([  "action":"$N一式「"+MAG+"怒剑狂花"+NOR+"」，手中$w舞出无数剑花，使$n难断虚实，无可躲避",
    "force" : 330,
    "lvl" : 36,
    "skill_name" : MAG "怒剑狂花" NOR,
    "damage_type":  "刺伤"
]),
([  "action":"$N手中$w斜指苍天，剑芒吞吐，一式「"+BLU+"九弧震日"+NOR+"」，对准$n的$l斜斜击出",
    "force" : 390,
    "lvl" : 44,
    "skill_name" : BLU "九弧震日" NOR,
    "damage_type":  "刺伤"
]),
([  "action":"$N一式「"+WHT+"漫天风雪"+NOR+"」，手腕急抖，挥洒出万点金光，刺向$n的$l",
    "force" : 480,
    "lvl" : 52,
    "skill_name" : WHT "漫天风雪" NOR,
    "damage_type":  "刺伤"
]),
([  "action":"$N一式「"+HIR+"天河倒泻"+NOR+"」，$w飞斩盘旋，如疾电般射向$n的胸口",
    "force" : 520,
    "lvl" : 60,
    "skill_name" : HIR "天河倒泻" NOR,
    "damage_type":  "刺伤"
]),
([  "action":"$N一式「"+HIY+"天外飞仙"+NOR+"」，$w突然从天而降，一片金光围掠$n全身",
    "force" : 520,
    "lvl" : 60,
    "skill_name" : HIY "天外飞仙" NOR,
    "damage_type":  "刺伤"
])
});
int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }
int practice_level(){   return 120;  }
int valid_learn(object me)
{
    object weapon;
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "sword")
    if (!objectp(weapon = me->query_temp("secondary_weapon"))
    || (string)weapon->query("skill_type") != "sword")
        return notify_fail("你还是先找把剑来吧。\n");

    if (me->query_skill("sword", 1)<=me->query_skill("tianyu-qijian",1))
        return notify_fail("你的基础不够，无法领会更高深的技巧。\n");
       if ((int)me->query_skill("bahuang-gong", 1) < 40)
        return notify_fail("你的八荒神功火候太浅。\n");

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
    level   = (int) me->query_skill("tianyu-qijian", 1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action = action[NewRandom(i, 20, level/5)];
                        break;
                }
    a_action["dodge"]  = 0-level*3;
    a_action["attack"]  = level/2;
    a_action["damage"] = level;
    return a_action;

}

int practice_skill(object me)
{
    object weapon;
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "sword")
    if (!objectp(weapon = me->query_temp("secondary_weapon"))
    || (string)weapon->query("skill_type") != "sword")
        return notify_fail("你使用的武器不对。\n");
    if ((int)me->query("qi") < 50)
        return notify_fail("你的体力不够练天羽奇剑。\n");
    me->receive_damage("qi", 25);
    return 1;
}
string perform_action_file(string action)
{
    return __DIR__"tianyu-qijian/" + action;
}
