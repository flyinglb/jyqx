// SKILL zhemei-shou.c
inherit SKILL;
mapping *action = ({
([  "action" : "$N一招「"+HIC+"吹梅笛怨"+NOR+"」，双手横挥，抓向$n",
    "force" : 130,
    "lvl" : 0,
    "skill_name" : BLK "吹梅笛怨" NOR,
    "damage_type" : "瘀伤"
]),
([  "action" : "$N一招「"+RED+"黄昏独自愁"+NOR+"」，身子跃然而起，抓向$n的头部",
    "force" : 150,
    "lvl" : 10,
    "skill_name" : RED "黄昏独自愁" NOR,
    "damage_type" : "瘀伤"
]),
([  "action" : "$N一招「"+GRN+"寒山一带伤心碧"+NOR+"」，双手纷飞，$n只觉眼花缭乱",
    "force" : 150,
    "lvl" : 30,
    "skill_name" : GRN "寒山一带伤心碧" NOR,
    "damage_type" : "瘀伤"
]),
([  "action" : "$N一招「"+YEL+"梅花雪落覆白苹"+NOR+"」，双手合击，$n只觉无处可避",
    "force" : 150,
    "lvl" : 40,
    "skill_name" : YEL "梅花雪落覆白苹" NOR,
    "damage_type" : "瘀伤"
]),
([  "action" : "$N一招「"+HIC+"砌下落梅如雪乱"+NOR+"」，双手飘然抓向$n",
    "force" : 250,
    "lvl" : 50,
    "skill_name" : HIC "砌下落梅如雪乱" NOR,
    "damage_type" : "瘀伤"
]),
([  "action" : "$N双手平举，一招「"+HIW+"云破月来花弄影"+NOR+"」击向$n",
    "force" : 300,
    "lvl" : 60,
    "skill_name" : HIW "云破月来花弄影" NOR,
            "damage_type" : "瘀伤"
]),
([  "action" : "$N一招「"+WHT+"花开堪折直须折"+NOR+"」，拿向$n，似乎$n的全身都被笼罩",
    "force" : 350,
    "lvl" : 70,
    "skill_name" : WHT "花开堪折直须折" NOR,
    "damage_type" : "内伤"
]),
([  "action" : "$N左手虚晃，右手一记「"+MAG+"红颜未老恩先绝"+NOR+"」击向$n的头部",
    "force" : 350,
    "lvl" : 80,
    "skill_name" : MAG "红颜未老恩先绝" NOR,
           "damage_type" : "瘀伤"
]),
([  "action" : "$N施出「"+RED+"虚妄笑红"+NOR+"」，右手横扫$n的$l，左手攻向$n的胸口",
    "force" : 400,
    "lvl" : 90,
    "skill_name" : RED "虚妄笑红" NOR,
            "damage_type" : "瘀伤"
]),
([  "action" : "$N施出「"+YEL+"玉石俱焚"+NOR+"」，不顾一切扑向$n",
    "force" : 450,
    "lvl" : 100,
    "skill_name" : YEL "玉石俱焚" NOR,
            "damage_type" : "瘀伤"
])
});
int valid_enable(string usage) { return usage=="hand" || usage=="parry"; }
int practice_level(){   return 100;  }

int valid_combine(string combo) { return combo=="liuyang-zhang"; }
int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("练天山折梅手必须空手。\n");
    if ((int)me->query("max_neili") < 50)
        return notify_fail("你的内力太弱，无法练天山折梅手。\n");
if (me->query_skill("hand", 1) <=me->query_skill("zhemei-shou", 1))
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
    level   = (int) me->query_skill("zhemei-shou",1);
    for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action=action[NewRandom(i, 20, level/5)];
                       break;
                 }
    a_action["dodge"]  = 0-level;
    a_action["attack"]  = level/2;
    a_action["damage"] = level;
    return a_action;
}

int practice_skill(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("练天山折梅手必须空手。\n");
    if ((int)me->query("qi") < 30)
        return notify_fail("你的体力太低了。\n");
    if ((int)me->query("neili") < 20)
        return notify_fail("你的内力不够练天山折梅手。\n");
    me->receive_damage("qi", 25);
    me->add("neili", -10);
    return 1;
}
string perform_action_file(string action)
{
    return __DIR__"zhemei-shou/" + action;
}
