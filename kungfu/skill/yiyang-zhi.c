// yizhi-chan.c 一阳指
inherit SKILL;
mapping *action = ({
([  "action" : "$N小指一弹，戳向$n的腰间，一指点过，立即缩回，只见$N身子未动，第二指已点向$n$l",
    "force" : 60,
    "lvl" : 0,
    "skill_name" : YEL "一阳指" NOR,
    "damage_type" : "刺伤",
]),
([  "action" : "但见$N手臂颤动，犹如蜻蜓点水，一口气尚未换过，已点$n各大要穴",
    "force" : 60,
    "lvl" : 50,
    "skill_name" : YEL "一阳指" NOR,
    "damage_type" : "刺伤",
]),
([  "action" : "$N忽地跃起，左掌抚胸，右手伸出食指，缓缓向$n$l上点去",
    "force" : 60,
    "lvl" : 100,
    "skill_name" : YEL "一阳指" NOR,
    "damage_type" : "刺伤"
]),
([  "action" : "只见$N龙行虎步，神威凛凛，倏忽之间，欺近身去点了$n$l，一点即离，快捷无伦",
    "force" : 80,
    "lvl" : 150,
    "skill_name" : YEL "一阳指" NOR,
    "damage_type" : "刺伤"
]),
([  "action" : "只见$N背向$n，倒退而行，反手出指，缓缓点向$n的$l",
    "force" : 100,
    "lvl" : 200,
    "skill_name" : YEL "一阳指" NOR,
    "damage_type" : "刺伤"
])
});
int valid_enable(string usage) { return usage=="unarmed"; }
int practice_level(){   return 100;  }
int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("练一阳指必须空手。\n");
    if ((int)me->query_skill("kumu-shengong", 1) < 20)
        return notify_fail("你的枯木神功火候不够，无法学一阳指。\n");
    if ((int)me->query("max_neili") < 100)
        return notify_fail("你的内力太弱，无法练一指禅。\n");
    if (me->query_skill("unarmed", 1) <=me->query_skill("yiyang-zhi", 1))
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
    int level=me->query_skill("yiyang-zhi",1);
    mapping a_action = action[random( sizeof(action) )];
    a_action["dodge"]  = 0-level*2;
    a_action["parry"]  = 0-level*2;
    a_action["damage"] = level*2;
    return a_action;
}
int practice_skill(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("练一阳指必须空手。\n");
    if ((int)me->query("qi") < 30)
        return notify_fail("你的体力太低了。\n");
    if ((int)me->query("neili") < 20)
        return notify_fail("你的内力不够练一指禅。\n");
    me->receive_damage("qi", 30);
    me->add("neili", -10);
    return 1;
}

