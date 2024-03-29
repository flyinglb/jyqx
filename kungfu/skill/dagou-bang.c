// dagou-bang.c
inherit SKILL;
mapping *action = ({
([  "action": "$N使出一招「"+BLK+"棒打双犬"+NOR+"」，手中$w化作两道青光砸向$n的$l",
    "force" : 50,
    "lvl" : 1,
    "damage_type": "挫伤"
]),
([  "action": "$N手中$w左右晃动，一招「"+RED+"拨草寻蛇"+NOR+"」向$n的$l攻去",
    "force" : 100,
    "lvl" : 33,
    "damage_type": "挫伤"
]),
([  "action": "$N举起$w，居高临下使一招「"+GRN+"打草惊蛇"+NOR+"」敲向$n的$l",
    "force" : 180,
    "lvl" : 66,
    "damage_type": "挫伤"
]),
([  "action": "$N施出「"+YEL+"拨狗朝天"+NOR+"」，$w由下往上向$n撩去",
    "force" : 250,
    "lvl" : 100,
    "damage_type": "挫伤"
]),
});
int practice_level(){   return 100;  }
int valid_enable(string usage) { return (usage == "staff") || (usage == "parry"); }
int valid_learn(object me)
{
    if ((int)me->query("max_neili") < 100)
        return notify_fail("你的内力不够。\n");
    if (me->query_skill("staff", 1) <=me->query_skill("dagou-bang", 1))
        return notify_fail("你的基础不够，无法领会更高深的技巧。\n");
    else
    return 1;
}
mapping query_action(object me, object weapon)
{
    mapping a_action;
    int level=me->query_skill("dagou-bang",1);
    if (random(me->query_skill("staff")) > 300 &&
        me->query_skill("force") > 60 &&
        me->query("neili") > 100 &&
        (string)weapon->query("id") == "yuzhu zhang" ) {
        me->add("neili", -100);
        return ([
        "action": "$N眼中射出一道青芒，手中玉竹杖使出「"+HIC+"天下无狗"+NOR+"」，劈天盖地般攻向$n",
        "attack": 100,
        "damage": 500,
        "dodge": -level*2,
        "force" : 300,
        "damage_type": "挫伤"]);
    }
    a_action = action[random(sizeof(action))];
    a_action["dodge"]  = 0-level;
    a_action["damage"] = level;
    return a_action;
}
 int practice_skill(object me)
 {
    object weapon;
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "staff")
    if (!objectp(weapon = me->query_temp("secondary_weapon"))
    || (string)weapon->query("skill_type") != "staff")
        return notify_fail("你使用的武器不对。\n");
    if ((int)me->query("qi") < 50)
        return notify_fail("你的体力不够练打狗棒法。\n");
    me->receive_damage("qi", 40);
    return 1;
 }


string perform_action_file(string action)
{
    return __DIR__"dagou-bang/" + action;
}
