// jinshe-jianfa.c 金蛇剑法
//  

#include <ansi.h>

inherit SKILL;

string *parry_msg = ({
        HIC "突然之间，$n身行蛇动，向后滑出丈许，躲过了$N这一招。\n", NOR
        HIC "$n手臂回转，手中$w竟如蛇般缠了过来。\n", NOR
        HIC "$n把$w交左手，右手在$N的肩上搭了过去，$N不由觉得一阵凉意。\n", NOR
        HIC "$n身形飘忽，移步到$N的身后，躲过了$N这一招。\n", NOR
        HIC "$N大吼一声，猛地攻了过去，却见$n身体不可思议地转了几个弯，躲过了这招。\n", NOR
        HIC "$N眼睛一花，$n突然冲天而起，状似蛟龙，躲过了这招。\n", NOR 
});


mapping *action = ({
([      "action": "$N突然间面现微笑，身行越来越慢，竟坐在了地上，手中$w却直刺$n的前胸",
        "force" : 80,
        "dodge" : 40,
        "damage": 80,
        "lvl" : 0,
        "skill_name" : "面带微笑",
        "damage_type":  "刺伤"
]),
([      "action":"$N身行蛇动，手中$w从不可思议的角度向$n的后背刺去",
        "force" : 80,
        "dodge" : 60,
        "damage": 100,
        "lvl" : 25,
        "skill_name" : "身行蛇动",
        "damage_type":  "刺伤"
]),
([      "action": HIY "突然间，$N身上发出万丈金光，$w脱鞘而出，向$n的前胸击去" NOR,
        "force" : 340,
        "dodge" : 20,
        "damage": 200,
        "lvl" : 100,
        "skill_name" :  "万丈金光",
        "damage_type":  "刺伤"
]),
([      "action":"$N抬眼望天，状极潇洒，$w竟从身后直飞$n头顶，$n一声惨叫",
        "force" : 380,
        "dodge" : 60,
        "damage": 260,
        "lvl" : 110,
        "skill_name" : "抬眼望天",
        "damage_type":  "刺伤"
]),
});


int valid_enable(string usage) 
{ 
    return usage == "sword" || usage == "parry"; 
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
        level   = (int) me->query_skill("jinshe-jian",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

string query_parry_msg(string limb)
{
        return parry_msg[random(sizeof(parry_msg))];
}

int valid_learn(object me)
{
//return notify_fail("金蛇剑法只能通过研习《金蛇剑谱》来学习。\n");
    object ob;
    if( (int)me->query_skill("jinshe-jian",1) < 200 )
        return notify_fail("金蛇剑法要200段以上才能自练。\n");
    if( (int)me->query("max_neili") < 500 )
        return notify_fail("你的内力不够，没有办法练金蛇剑法。\n");
    if( !(ob = me->query_temp("weapon"))
        ||(string)ob->query("skill_type") != "sword" )
    return notify_fail("你必须先找一把剑才能练剑法。\n");

    return 1;
// modify by risc
}
string perform_action_file(string action)
{
        return __DIR__"jinshe-jian/" + action;
}

int practice_skill(object me)
{
    object weapon;
    if (!objectp(weapon = me->query_temp("weapon"))
       ||(string)weapon->query("skill_type") != "sword")
    if (!objectp(weapon = me->query_temp("secondary_weapon"))
       ||(string)weapon->query("skill_type") != "sword")
    return notify_fail("你使用的武器不对。\n");
    if ((int)me->query("qi") < 50)
         return notify_fail("你的体力不够练金蛇剑法。\n");
    me->receive_damage("qi", 30);
    return 1;
}
