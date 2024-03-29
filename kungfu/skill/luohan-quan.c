// luohan-quan.c 罗汉拳
inherit SKILL;
mapping *action = ({
([  "action" : "$N连续上步，一式「"+YEL+"黄莺落架"+NOR+"」，左右手分靠，变拳为掌，击向$n的$l",
    "force" : 180,
    "lvl" : 0,
    "skill_name" : YEL "黄莺落架" NOR,
        "damage_type" : "瘀伤"
]),
([  "action" : "$N左脚虚踏，全身右转，一招「"+RED+"丹凤朝阳"+NOR+"」，右掌猛地插向$n的$l",
    "force" : 200,
    "lvl" : 8,
    "skill_name" : RED "丹凤朝阳" NOR,
        "damage_type" : "瘀伤"
]),
([  "action" : "$N双手大开大阖，宽打高举，使一招「"+MAG+"洛钟东应"+NOR+"」，双拳向$n的$l打去",
    "force" : 220,
    "lvl" : 15,
    "skill_name" : MAG "洛钟东应" NOR,
        "damage_type" : "瘀伤"
]),
([  "action" : "$N左掌圈花扬起，屈肘当胸，虎口朝上，一招「"+WHT+"偏花七星"+NOR+"」打向$n的$l",
    "force" : 260,
    "lvl" : 24,
    "skill_name" : WHT "偏花七星" NOR,
        "damage_type" : "瘀伤"
]),
([  "action" : "$N使一招「"+HIB+"苦海回头"+NOR+"」，上身前探，双手划了个半圈，击向$n的$l",
    "force" : 300,
    "lvl" : 33,
    "skill_name" : HIB "苦海回头" NOR ,
    "damage_type" : "瘀伤"
]),
([  "action" : "$N双掌划弧，一记「"+GRN+"挟山超海"+NOR+"」，掌出如电，一下子切到$n的手上",
    "force" : 360,
    "lvl" : 42,
    "skill_name" : GRN "挟山超海" NOR,
        "damage_type" : "瘀伤"
]),
([  "action" : "$N施出「"+WHT+"慑服外道"+NOR+"」，双拳拳出如风，同时打向$n头，胸，腹三处要害",
    "force" : 420,
    "lvl" : 50,
    "skill_name" : WHT "慑服外道" NOR,
        "damage_type" : "瘀伤"
]),
([  "action" : "$N左脚内扣，右腿曲坐，一式「"+HIC+"三入地狱"+NOR+"」，双手齐齐按向$n的胸口",
    "force" : 480,
    "lvl" : 58,
    "skill_name" : HIC "三入地狱" NOR,
        "damage_type" : "瘀伤"
]),
});
int valid_enable(string usage) { return usage=="cuff" || usage=="parry"; }
int practice_level(){   return 58;  }
int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("学罗汉拳必须空手。\n");
    if ((int)me->query("max_neili") < 50)
        return notify_fail("你的内力太弱，无法练罗汉拳。\n");
  if (me->query_skill("cuff", 1) <=me->query_skill("luohan-quan", 1))
        return notify_fail("你的基础不够，无法领会更高深的技巧。\n");
    if ((int)me->query_skill("hunyuan-yiqi", 1) < 20)
    if ((int)me->query_skill("yijing-force", 1) < 20)
    if ((int)me->query_skill("jiuyang-shengong", 1) < 20)
    if ((int)me->query_skill("taiji-shengong", 1) < 20)
        return notify_fail("你的禅宗气功火候不够，无法学罗汉拳。\n");
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
    level   = (int) me->query_skill("luohan-quan",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action = action[NewRandom(i, 20, level/5)];
                        break;
                }
    a_action["dodge"]  = 0-level/3;
    a_action["damage"] = level+random(level);
    return a_action;

}

int practice_skill(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("练罗汉拳必须空手。\n");
    if ((int)me->query("qi") < 30)
        return notify_fail("你的体力太低了。\n");
    if ((int)me->query("neili") < 20)
        return notify_fail("你的内力不够练罗汉拳。\n");
    me->receive_damage("qi", 25);
    me->add("neili", -5);
    return 1;
}


