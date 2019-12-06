// 五毒钩法

inherit SKILL;

mapping *action = ({
([	"action" : "$N一式「"+HIG+"神龙弯身"+NOR+"」，$w化做一条蛇状，从一个古怪的角度击向$n的腰间",
	"force" : 120,
        "dodge" : -10,
	"damage" : 50,
	"lvl" : 0,
	"skill_name" : "神龙弯身",
	"damage_type" : "刺伤"
]),
([	"action" : "$N微退半步，手中$w使出一式「"+HIR+"蜘蛛吐丝"+NOR+"」，分化数招攻向$n的$l",
	"force" : 140,
        "dodge" : -10,
	"damage" : 80,
	"lvl" : 15,
	"skill_name" : "蜘蛛吐丝",
	"damage_type" : "刺伤"
]),
([	"action" : "$N反手舞动$w，一招「"+HIW+"蝎子交尾"+NOR+"」从背后划道弧线刺向$n的$l",
	"force" : 170,
        "dodge" : 5,
	"damage" : 95,
	"lvl" : 30,
	"skill_name" : "蝎子交尾",
	"damage_type" : "刺伤"
]),
([	"action" : "$N一式「"+HIB+"蜈蚣穿靴"+NOR+"」，$w从左右两侧幻做数道剑光，向$n的$l挥去",
	"force" : 190,
        "dodge" : 5,
	"damage" : 120,
	"lvl" : 45,
	"skill_name" : "蜈蚣穿靴",
	"damage_type" : "刺伤"
]),
([	"action" : "$N回身拧腰，右手虚抱成圆，一式「"+HIY+"蟾蜍吞雾"+NOR+"」，$w中宫直进，刺向$n的胸口",
	"force" : 240,
        "dodge" : 10,
	"damage" : 120,
	"lvl" : 60,
	"skill_name" : "蟾蜍吞雾",
	"damage_type" : "刺伤"
]),
([	"action" : "$N一式「"+HIM+"五圣交辉"+NOR+"」，$w从五个虚招中分出，挟爆裂之声骤然斩向$n的$l",
	"force" : 280,
        "dodge" : 5,
	"damage" : 200,
	"lvl" : 75,
	"skill_name" : "五圣交辉",
	"damage_type" : "刺伤"
]),
});

int valid_enable(string usage) { return (usage == "sword" || usage == "parry"); }

int valid_learn(object me)
{
	object ob;

	if( !(ob = me->query_temp("weapon"))
	||	(string)ob->query("skill_type") != "sword" )
		return notify_fail("你必须先找一把剑才能练五毒钩法。\n");
        if ((int)me->query("max_neili") < 150)
                 return notify_fail("你的内力不够。\n");
	if ((int)me->query_skill("wudu-shengong", 1)<50)
		return notify_fail("你的五毒神功火候不够，无法学习五毒钩法。\n");
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

        level   = (int) me->query_skill("wudu-goufa",1);
	for(i = sizeof(action); i > 0; i--)
	if(level > action[i-1]["lvl"])
		return action[random(i)];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("你的体力不够练五毒钩法。\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("你的内力不够练五毒钩法。\n");
	me->receive_damage("qi", 25);
	return 1;
}

string perform_action_file(string action)
{
    return __DIR__"wudu-goufa/" + action;
}
