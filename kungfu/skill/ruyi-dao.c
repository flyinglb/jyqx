// ruyi-dao.c - 如意刀法

inherit SKILL;
mapping *action = ({
([      "action" : "$N一磕刀柄，一招「"+WHT+"若往若返"+NOR+"」，猛地一个转身，手中$w直向$n斩去",
        "force"         : 80,
        "lvl"           : 0,
        "skill_name"    : WHT "若往若返" NOR,
        "damage_type"   : "割伤"
]),
([      "action" : "$N把手中的$w一扬，一招「"+YEL+"峰回路转"+NOR+"」，手中的刀一个急转，直砍向$n的$l",
        "force"         : 100,
        "lvl"           : 10,
        "skill_name"    : YEL "峰回路转" NOR,
        "damage_type"   : "割伤"
]),
([      "action" : "$N身形陡然滑出数尺，一招「"+RED+"御风而行"+NOR+"」，刀势如风，手中$w斩向$n的$l",
        "force"         : 120,
        "lvl"           : 20,
        "skill_name"    : RED "御风而行" NOR,
        "damage_type"   : "割伤"
]),
([      "action" : "$N一招「"+HIW+"云雾萦绕"+NOR+"」，身子骤然拔高数尺，手中$w一个平推向$n的$l砍去。",
        "force"         : 140,
        "lvl"           : 30,
        "skill_name"    : HIW "云雾萦绕" NOR,
        "damage_type"   : "刺伤"
]),
([      "action" : "$N纵身一跃，手中$w一招「"+HIY+"金光泻地"+NOR+"」轻飘飘地向$n的$l要害掠去",
        "force"         : 160,
        "lvl"           : 40,
        "skill_name"    : HIY "金光泻地" NOR,
        "damage_type"   : "割伤"
]),
([      "action" : "$N手中$w向外一分，轻轻颤动，一招「"+BOLD+"柳暗花明"+NOR+"」反手向$n$l掠去",
        "force"         : 180,
        "lvl"           : 50,
        "skill_name"    : BOLD "柳暗花明" NOR,
        "damage_type"   : "割伤"
]),
([      "action" : "$N横刀上前，身形一转，手中$w使一招「"+CYN+"空谷秋虹"+NOR+"」画出一道光弧斩向$n的$l",
        "force"         : 200,
        "lvl"           : 60,
        "skill_name"    : CYN "空谷秋虹" NOR,
        "damage_type"   : "割伤"
]),
([      "action" : "$n只觉眼前一花，$N一招「"+HIM+"紫气东来"+NOR+"」，$w挟呼呼风声迅猛砍向$n的$l",
        "force"         : 220,
        "lvl"           : 70,
        "skill_name"    : HIM "紫气东来" NOR,
        "damage_type"   : "割伤"
]),
([      "action" : "$N把$w划了一圈，一招「"+HIC+"神光离合"+NOR+"」，$n只觉得全身被笼罩在一团刀气之中。",
        "force"         : 240,
        "lvl"           : 80,
        "skill_name"    : HIC "神光离合" NOR,
        "damage_type"   : "割伤"
]),
([      "action" : "$N身形一转，一招「"+HIB+"逍遥自在"+NOR+"」，$w刀光不定，招招砍向$n的$l要害",
        "force"         : 260,
        "lvl"           : 100,
        "skill_name"    : HIB "逍遥自在" NOR,
        "damage_type"   : "割伤"
]),
});
int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }
int practice_level(){   return 100;  }
int valid_combine(string combo) { return combo=="fumo-jian"; }
int valid_learn(object me)
{
    if ((int)me->query("max_neili") < 50)
        return notify_fail("你的内力不够。\n");
    if ((int)me->query_skill("beiming-shengong", 1) < 20 )
    if ((int)me->query_skill("yijing-force", 1) < 20)
        return notify_fail("你的北冥神功火候太浅。\n");
    if (me->query_skill("blade", 1) <=me->query_skill("ruyi-dao", 1))
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
    level   = (int) me->query_skill("ruyi-dao", 1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action = action[NewRandom(i, 20, level/5)];
                        break;
                }
    a_action["dodge"]  = 0-level;
    a_action["parry"]  = 0-level;
    a_action["attack"]  = level;
    a_action["damage"] = level*3;
    return a_action;

}
int practice_skill(object me)
{
    object weapon;
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "blade")
    if (!objectp(weapon = me->query_temp("secondary_weapon"))
    || (string)weapon->query("skill_type") != "blade")
        return notify_fail("你使用的武器不对。\n");
    if ((int)me->query("qi") < 50)
        return notify_fail("你的体力不够练如意刀法。\n");
    me->receive_damage("qi", 25);
    return 1;
}
string perform_action_file(string action)
{
        return __DIR__"ruyi-dao/" + action;
}

