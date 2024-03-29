// nianhua-zhi.c -拈花指
inherit SKILL;
mapping *action = ({
([  "action" : "$N侧身抬臂，右指划了个半圈，一式「"+HIC+"瓶花落砚"+NOR+"」击向$n的$l",
    "force" : 60,
    "lvl" : 0,
    "skill_name" : HIC "瓶花落砚" NOR,
    "damage_type" : "刺伤"
]),
([  "action" : "$N左掌虚托，一式「"+HIW+"寒梅吐蕊"+NOR+"」，右指穿腋疾出，指向$n的胸前",
    "force" : 70,
    "lvl" : 12,
    "skill_name" : "寒梅吐蕊",
        "damage_type" : "刺伤"
]),
([  "action" : "$N俯身斜倚，左手半推，右手一式「"+YEL+"初杏问酒"+NOR+"」，向$n的$l划过",
    "force" : 90,
    "lvl" : 17,
    "skill_name" : YEL "初杏问酒" NOR,
        "damage_type" : "刺伤"
]),
([  "action" : "$N双目微睁，一式「"+BLU+"露草斜阳"+NOR+"」，双手幻化出千百个指影，拂向$n的$l",
    "force" : 120,
    "lvl" : 24,
    "skill_name" : BLU "露草斜阳" NOR,
        "damage_type" : "刺伤"
]),
([  "action" : "$N一式「"+BLK+"仰月承霖"+NOR+"」，左掌护住丹田，右手斜指苍天，蓄势点向$n的$l",
    "force" : 160,
    "lvl" : 36,
    "skill_name" : BLK "仰月承霖" NOR,
        "damage_type" : "刺伤"
]),
([  "action" : "$N双掌平托胸前，十指叉开，一式「"+HIG+"叶底留莲"+NOR+"」，指向$n的周身大穴",
    "force" : 210,
    "lvl" : 50,
    "skill_name" : HIG "叶底留莲" NOR,
        "damage_type" : "刺伤"
]),
([  "action" : "$N双掌翻飞，一式「"+HIY+"清风拂桂"+NOR+"」，指端迸出无数道劲气，射向$n的全身",
    "force" : 270,
    "lvl" : 70,
    "skill_name" : HIY "清风拂桂" NOR,
        "damage_type" : "刺伤"
]),
([  "action" : "$N一式「"+YEL+"菊圃秋霜"+NOR+"」，并指如刃，一束束锐利无俦的刀气，凌虚向$n的$l砍去",
    "force" : 340,
    "lvl" : 84,
    "skill_name" : YEL "菊圃秋霜" NOR,
        "damage_type" : "刺伤"
]),
([  "action" : "$N一式「"+WHT+"伽叶微笑"+NOR+"」，双手食指交叉，指端射出一缕罡气，穿过$n的$l",
    "force" : 420,
    "lvl" : 95,
    "skill_name" : WHT "伽叶微笑" NOR,
        "damage_type" : "刺伤"
]),
([  "action" : "$N左掌竖立胸前，一式「"+YEL+"佛"+BLU+"祖"+RED+"拈花"+NOR+"」，右手食指扣住拇指，轻轻对着$n一弹",
    "force" : 510,
    "lvl" : 112,
    "skill_name" : RED "佛祖拈花" NOR,
        "damage_type" : "刺伤"
])
});
int valid_enable(string usage) { return usage=="finger" || usage=="parry"; }
int practice_level(){   return 122;  }
int valid_combine(string combo) { return combo=="sanhua-zhang"; }
int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("学拈花指必须空手。\n");
    if ((int)me->query("max_neili") < 100)
        return notify_fail("你的内力太弱，无法学拈花指。\n");
if (me->query_skill("finger", 1) <=me->query_skill("nianhua-zhi", 1))
        return notify_fail("你的基础不够，无法领会更高深的技巧。\n");

    if ((int)me->query_skill("hunyuan-yiqi", 1) < 20)
    if ((int)me->query_skill("yijing-force", 1) < 20)
    if ((int)me->query_skill("jiuyang-shengong", 1) < 20)
    if ((int)me->query_skill("taiji-shengong", 1) < 20)
    return notify_fail("你的禅宗气功火候不够，无法学拈花指。\n");

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
    int i, level;
    mapping a_action;
        level   = (int) me->query_skill("nianhua-zhi",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action = action[NewRandom(i, 20, level/5)];
                        break;
                }
    a_action["dodge"]  = 0-level;
    a_action["parry"]  = 0-random(level/3);
    a_action["attack"]  = level/3;
    a_action["damage"] = level/3;
    return a_action;
}
int practice_skill(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("练拈花指必须空手。\n");
    if ((int)me->query("qi") < 40)
        return notify_fail("你的体力太低了。\n");
    if ((int)me->query("neili") < 20)
        return notify_fail("你的内力不够练拈花指。\n");
    me->receive_damage("qi", 40);
    me->add("neili", -20);
    return 1;
}
string perform_action_file(string action)
{
    return __DIR__"nianhua-zhi/" + action;
}
