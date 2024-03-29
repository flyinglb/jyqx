// fengyun-shou.c -风云手
inherit SKILL;
mapping *action = ({
([  "action" : "$N一式「"+RED+"风满长空"+NOR+"」，以掌化爪，五指如钩，直逼$n的膻中要穴",
    "force" : 120,
        "lvl" : 0,
        "skill_name" : RED "风满长空" NOR,
    "damage_type" : "瘀伤"
]),
([  "action" : "$N左手虚晃，一式「"+RED+"烈火腾云"+NOR+"」，右手上下直击，反扣$n的肩井大穴",
    "force" : 130,
        "lvl" : 8,
        "skill_name" : RED "烈火腾云" NOR,
        "damage_type" : "瘀伤"
]),
([  "action" : "$N使一式「"+HIG+"草深雾泽"+NOR+"」，掌指齐出，拍拿并施，拿向$n的三路要害",
    "force" : 150,
        "lvl" : 16,
        "skill_name" : HIG "草深雾泽" NOR,
        "damage_type" : "瘀伤"
]),
([  "action" : "$N左手鹰抓，右手蛇举，一式「"+YEL+"天目昭辉"+NOR+"」疾扣$n的中节大脉",
    "force" : 180,
        "lvl" : 24,
        "skill_name" : YEL "天目昭辉" NOR,
        "damage_type" : "瘀伤"
]),
([  "action" : "$N使一式「"+HIW+"雷震四方"+NOR+"」，四面八方出现无数掌影，一爪突出，抓向$n的胸口",
    "force" : 220,
        "lvl" : 40,
        "skill_name" : HIW "雷震四方" NOR,
        "damage_type" : "内伤"
]),
([  "action" : "$N两手环扣，全身关节啪啪作响，一式「"+BLU+"水到渠成"+NOR+"」，击向$n的$l",
    "force" : 270,
        "lvl" : 48,
        "skill_name" : BLU "水到渠成" NOR,
        "damage_type" : "内伤"
]),
([  "action" : "$N一式「"+HIG+"山高林密"+NOR+"」，十指齐伸，遮天蔽日般地笼罩$n的全身要穴",
    "force" : 330,
        "lvl" : 54,
        "skill_name" : HIG "山高林密" NOR,
        "damage_type" : "内伤"
]),
([  "action" : "$N岳立霆峙，一式「"+YEL+"地老天荒"+NOR+"」，在一阵暴雷声中，双手同时拍中$n的七道死穴",
    "force" : 400,
        "lvl" : 60,
        "skill_name" : YEL "地老天荒" NOR,
        "damage_type" : "内伤"
])
});
int valid_enable(string usage) { return usage=="hand" || usage=="parry"; }
int practice_level(){   return 60;  }
int valid_combine(string combo) { return combo=="yingzhua-gong"; }
int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("练风云手必须空手。\n");
    if ((int)me->query_skill("hunyuan-yiqi", 1) < 20)
    if ((int)me->query_skill("yijing-force", 1) < 20)
    if ((int)me->query_skill("jiuyang-shengong", 1) < 20)
    if ((int)me->query_skill("taiji-shengong", 1) < 20)
        return notify_fail("你的禅宗气功火候不够，无法学风云手。\n");

    if ((int)me->query("max_neili") < 100)
        return notify_fail("你的内力太弱，无法练风云手。\n");
if (me->query_skill("hand", 1) <=me->query_skill("fengyun-shou", 1))
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
    int i, level;
    mapping a_action;
    level   = (int) me->query_skill("fengyun-shou",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action = action[NewRandom(i, 20, level/5)];
                        break;
                }
    a_action["dodge"]  = 0-level/2;
    a_action["parry"]  = 0-level/2;
    a_action["damage"] = level;
    return a_action;
}
int practice_skill(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("练风云手必须空手。\n");
    if ((int)me->query("qi") < 30)
        return notify_fail("你的体力太低了。\n");
    if ((int)me->query("neili") < 20)
        return notify_fail("你的内力不够练风云手。\n");
    me->receive_damage("qi", 25);
    me->add("neili", -5);
    return 1;
}
