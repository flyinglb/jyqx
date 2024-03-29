// jingang-quan.c -大金刚拳
inherit SKILL;
mapping *action = ({
([  "action" : "$N盘膝而坐，二手合十，一式「"+YEL+"莲花座"+NOR+"」，双拳蓄势而发，击向$n的$l",
    "force" : 180,
    "lvl" : 0,
    "skill_name" : YEL "莲花座" NOR,
    "damage_type" : "瘀伤"
]),
([  "action" : "$N一式「"+RED+"烈火锥"+NOR+"」，双掌轮流下击，拳势如焰，吡啪爆响",
    "force" : 200,
    "lvl" : 10,
    "skill_name" : RED "烈火锥" NOR,
        "damage_type" : "瘀伤"
]),
([  "action" : "$N腾空飞起，一式「"+HIW+"八方雨"+NOR+"」，双手双腿齐出，令$n无可躲藏",
    "force" : 230,
    "lvl" : 20,
    "skill_name" : HIW "八方雨" NOR,
        "damage_type" : "瘀伤"
]),
([  "action" : "$N双掌虚含，掌缘下沉，一式「"+BLU+"掌心雷"+NOR+"」，缓缓向$n推出",
    "force" : 270,
    "lvl" : 30,
    "skill_name" : BLU "掌心雷" NOR,
        "damage_type" : "瘀伤"
]),
([  "action" : "$N一臂前伸，一臂后指，一式「"+HIY+"五指山"+NOR+"」，攻向$n的身前身后",
    "force" : 320,
    "lvl" : 40,
    "skill_name" : HIY "五指山" NOR,
        "damage_type" : "瘀伤"
]),
([  "action" : "$N一式「"+RED+"观音渡"+NOR+"」，两手十指虚点$n的全身三十六道要穴",
    "force" : 380,
    "lvl" : 48,
    "skill_name" : RED "观音渡" NOR,
        "damage_type" : "瘀伤"
]),
([  "action" : "$N两目内视，双手内笼，一式「"+YEL+"天龙唱"+NOR+"」，四面八方响起震人心魄的龙吟",
    "force" : 450,
    "lvl" : 54,
    "skill_name" : YEL "天龙唱" NOR,
        "damage_type" : "瘀伤"
]),
([  "action" : "$N似笑非笑，双拳无形无定，一式「"+YEL+"如来笑"+NOR+"」，骤然击向$n的前胸",
    "force" : 530,
    "lvl" : 60,
    "skill_name" : YEL "如来笑" NOR,
        "damage_type" : "瘀伤"
])
});
int valid_enable(string usage) { return  usage=="cuff" || usage=="parry"; }
int practice_level(){   return 60;  }
int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("练大金刚拳必须空手。\n");
    if ((int)me->query("max_neili") < 100)
        return notify_fail("你的内力太弱，无法练大金刚拳。\n");
 if (me->query_skill("cuff", 1) <=me->query_skill("jinggang-quan", 1))
        return notify_fail("你的基础不够，无法领会更高深的技巧。\n");

    if ((int)me->query_skill("hunyuan-yiqi", 1) < 20)
    if ((int)me->query_skill("yijing-force", 1) < 20)
    if ((int)me->query_skill("jiuyang-shengong", 1) < 20)
    if ((int)me->query_skill("taiji-shengong", 1) < 20)
        return notify_fail("你的禅宗气功火候不够，无法学大金刚拳。\n");

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
    level   = (int) me->query_skill("jingang-quan",1);
    for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action=action[NewRandom(i, 20, level/5)];
                       break;
                 }
    a_action["dodge"]  = 0-level;
    a_action["parry"]  = 0-level;
    a_action["damage"] = level*2;
    return a_action;
}

int practice_skill(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("练大金刚拳必须空手。\n");
    if ((int)me->query("qi") < 30)
        return notify_fail("你的体力太低了。\n");
    if ((int)me->query("neili") < 20)
        return notify_fail("你的内力不够练大金刚拳。\n");
    me->receive_damage("qi", 30);
    me->add("neili", -10);
    return 1;
}
string perform_action_file(string action)
{
    return __DIR__"jingang-quan/" + action;
}

