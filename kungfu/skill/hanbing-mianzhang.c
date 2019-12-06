// hannbing-mianzhang.c 寒冰绵掌
// pal 1997.05.26
inherit SKILL;
mapping *action = ({
([  "action" : "$N一式「"+RED+"大江东去"+NOR+"」，双掌大开大合，直向$n的$l击去",
    "force" : 180,
    "lvl" : 0,
    "skill_name" : RED "大江东去" NOR,
        "damage_type" : "瘀伤"
]),
([  "action" : "$N身形一变，一式「"+YEL+"黄河九曲"+NOR+"」，双掌似曲似直，拍向$n的$l",
    "force" : 220,
    "lvl" : 10,
    "skill_name" : YEL "黄河九曲" NOR, 
        "damage_type" : "瘀伤"
]),
([  "action" : "$N使一式「"+BLU+"湖光山色"+NOR+"」，左掌如微风拂面，右掌似细雨缠身，直取$n的$l",
    "force" : 260,
    "lvl" : 20,
    "skill_name" : BLU "湖光山色" NOR,
        "damage_type" : "瘀伤"
]),
([  "action" : "$N两掌一分，一式「"+MAG+"曾经沧海"+NOR+"」，隐隐发出潮声，向$n横击过去",
    "force" : 300,
    "lvl" : 30,
    "skill_name" : MAG "曾经沧海" NOR,
        "damage_type" : "瘀伤"
]),
([  "action" : "$N身形一转，使出一式「"+BLU+"水光潋滟"+NOR+"」，只见漫天掌影罩住了$n的全身",
    "force" : 340,
    "lvl" : 40,
    "skill_name" : BLU "水光潋滟" NOR,
        "damage_type" : "瘀伤"
]),
([  "action" : "$N突然身形一缓，使出一式「"+RED+"小雨初晴"+NOR+"」，左掌凝重，右掌轻盈，击往$n的$l",
    "force" : 380,
    "lvl" : 50,
    "skill_name" : RED "小雨初晴" NOR,
        "damage_type" : "瘀伤"
]),
([  "action" : "$N使一式「"+HIW+"风雪江山"+NOR+"」，双掌挟狂风暴雪之势，猛地劈向$n的$l",
    "force" : 420,
    "lvl" : 60,
    "skill_name" : HIW "风雪江山" NOR,
        "damage_type" : "瘀伤"
]),
([  "action" : "$N一招「"+HIW+"霜华满地"+NOR+"」，双掌带着萧瑟的秋气，拍向$n的$l",
    "force" : 460,
    "lvl" : 70,
    "skill_name" : RED "霜华满地" NOR,
        "damage_type" : "瘀伤"
]),
([  "action" : "$N身法陡然一变，使出一式「"+YEL+"仙乡冰舸"+NOR+"」，掌影千变万幻，令$n无法躲闪",
    "force" : 500,
    "lvl" : 80,
    "skill_name" : YEL "仙乡冰舸" NOR,
        "damage_type" : "瘀伤"
]),
([  "action" : "$N清啸一声，一式「"+MAG+"冰霜雪雨"+NOR+"」，双掌挥舞，如同雪花随风而转，击向$n的$l",
    "force" : 540,
    "lvl" : 90,
    "skill_name" : MAG "冰霜雪雨" NOR,
        "damage_type" : "瘀伤"
])
});
int practice_level(){   return 90;  }
int valid_enable(string usage)
{
    return usage=="unarmed" || usage=="parry" ;
}
int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("练寒冰绵掌必须空手。\n");
//    if ((int)me->query_skill("huagong-dafa", 1) < 20)
//        return notify_fail("你的化功大法火候不够，无法学寒冰绵掌。\n");
    if ((int)me->query("max_neili") < 100)
        return notify_fail("你的内力太弱，无法练寒冰绵掌。\n");
    if (me->query_skill("unarmed", 1) <=me->query_skill("hanbing-mianzhang", 1))
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
    level   = (int) me->query_skill("hanbing-mianzhang",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action = action[NewRandom(i, 20, level/5)];
                        break;
                }
/*
    a_action["dodge"]  = 0-level/2;
    a_action["parry"]  = 0-random(level/2);
    a_action["damage"] = level;
*/
    return a_action;
}

int practice_skill(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("练寒冰绵掌必须空手。\n");
    if ((int)me->query("qi") < 30)
        return notify_fail("你的体力太低了。\n");
    if ((int)me->query("neili") < 40)
        return notify_fail("你的内力不够练寒冰绵掌。\n");
    me->receive_damage("qi", 30);
    me->add("neili", -10);
    return 1;
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
if( random(me->query_skill("hanbing-mianzhang")) > 10 )
    victim->apply_condition("ice_poison", random(me->query_skill("hanbing-mianzhang",1)/10) + 1 + victim->query_condition("ice_poison"));
}
string perform_action_file(string action)
{
    return __DIR__"hanbing-mianzhang/" + action;
}

