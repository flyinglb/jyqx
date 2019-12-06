//qianzhu-wandushou 千蛛万毒手
#include <ansi.h>
inherit SKILL;

mapping *action = ({
([  "action" : "$N手上隐现古怪颜色，自上而下撕扯$n的$l",
    "force" : 120,
    "dodge" : 10,
    "damage": 30,
    "lvl" : 0,
    "skill_name" : "千色万变" ,
    "damage_type" : "抓伤"
]),
([  "action" : "$N双手忽隐忽现，招招鬼魅般拍向$n的$l",
    "force" : 150,
    "dodge" : 20,
    "damage": 45,
    "lvl" : 30,
    "skill_name" : "千隐万现" ,
    "damage_type" : "淤伤"
]),
([  "action" : "$N身形围$n一转，钩手成抓，对着$n的$l抓下",
    "force" : 180,
    "dodge" : 30,
    "damage": 55,
    "lvl" : 60,
    "skill_name" : "千憧万影" ,
    "damage_type" : "抓伤"
]),
([  "action" : "$N一声怪叫，反手为拳，从正中直击$n的小腹",
    "force" : 240,
    "dodge" : 50,
    "skill_name" : "千蛛万毒" ,
    "damage": 100,
    "lvl"   : 100,
    "damage_type" : "内伤"
]),
});

int valid_enable(string usage) { return usage=="unarmed" ||  usage=="parry"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
            return notify_fail("练千蛛万毒手必须空手。\n");
        if ((int)me->query("max_neili") < 100)
            return notify_fail("你的内力太弱，无法练千蛛万毒手。\n");
	return 1;
}

string query_skill_name(int level)
{
	int i;
	for(i = sizeof(action); i > 0; i--)
		if(level >= action[i-1]["lvl"])
			return action[i-1]["skill_name"];
}

mapping query_action(object me, object weapon)
{
	int i, level;
	level = (int) me->query_skill("qianzhu-wandushou",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
            return action[NewRandom(i, 5, level/5)];

}
int practice_skill(object me)
{
        int skill;

	skill = me->query_skill("qianzhu-wandushou",1);
	if ((int)me->query("qi") < 30)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("你的内力不够练千蛛万毒手。\n");
	me->receive_damage("qi", 30);
        me->add("neili", -10);
	return 1;
}
string perform_action_file(string action)
{
    return __DIR__"qianzhu-wandushou/" + action;
}
