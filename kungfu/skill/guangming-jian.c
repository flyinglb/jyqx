// guangming-jian - 大光明剑法

inherit SKILL;

mapping *action = ({
([	"action" : "$N一式「熊熊圣火」，剑锋平指，剑势如风，一气呵成横扫$n的腰间",
	"force" : 120,
        "dodge" : -10,
	"damage" : 25,
	"lvl" : 0,
	"skill_name" : "熊熊圣火",
	"damage_type" : "刺伤"
]),
([	"action" : "$N向前跃上一步，左手剑诀，右手$w使出一式「焚我残躯」直刺$n的$l",
	"force" : 140,
        "dodge" : -10,
	"damage" : 30,
	"lvl" : 10,
	"skill_name" : "焚我残躯",
	"damage_type" : "刺伤"
]),
([	"action" : "$N舞动$w，一招「光明世人」挟著无数剑光洒向$n的$l",
	"force" : 170,
        "dodge" : 5,
	"damage" : 35,
	"lvl" : 20,
	"skill_name" : "光明世人",
	"damage_type" : "刺伤"
]),
([	"action" : "$N一式「万象归尘」，$w自左而右划出一个大弧，向$n的$l挥去",
	"force" : 190,
        "dodge" : 5,
	"damage" : 40,
	"lvl" : 30,
	"skill_name" : "万象归尘",
	"damage_type" : "刺伤"
]),
([	"action" : "$N回身拧腰，右手虚抱成圆，一式「生亦何欢」，$w中宫直进，刺向$n的胸口",
	"force" : 240,
        "dodge" : 10,
	"damage" : 50,
	"lvl" : 40,
	"skill_name" : "生亦何欢",
	"damage_type" : "刺伤"
]),
([	"action" : "$N一式「死亦何苦」，$w从上至下猛劈，剑锋直出，挟爆裂之声骤然斩向$n的$l",
	"force" : 280,
        "dodge" : 5,
	"damage" : 60,
	"lvl" : 49,
	"skill_name" : "死亦何苦",
	"damage_type" : "刺伤"
]),
([	"action" : "$N运气施出「怜我世人」，$w剑尖逼出一道青芒，闪电般破空射向$n的$l",
	"force" : 350,
        "dodge" : 5,
	"damage" : 75,
	"lvl" : 57,
	"skill_name" : "怜我世人",
	"damage_type" : "刺伤"
]),
([	"action" : "$N双腿半屈半蹲，一式「天下光明」，剑尖划出无数圆圈，狂风骤起，笼罩天地",
	"force" : 400,
        "dodge" : 5,
	"damage" : 90,
	"lvl" : 64,
	"skill_name" : "天下光明",
	"damage_type" : "刺伤"
]),
});

int valid_enable(string usage) { return (usage == "sword" || usage == "parry"); }

int valid_learn(object me)
{
	object ob;

	if( !(ob = me->query_temp("weapon"))
	||	(string)ob->query("skill_type") != "sword" )
		return notify_fail("你必须先找一把剑才能练剑法。\n");
	if ((int)me->query("max_force") < 150)
		return notify_fail("你的内力不够。\n");
	if ((int)me->query_skill("sunforce", 1) < (int)me->query_skill("guangming-jian", 1) 
		&& me->query_skill("guangming-quan", 1) > 60 )
		return notify_fail("你的光明神功火候不够，无法学更高深的大光明剑法。\n");
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

	level   = (int) me->query_skill("guangming-jian",1);
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
	if ((int)me->query("kee") < 50)
		return notify_fail("你的体力不够练大光明剑法。\n");
	me->receive_damage("kee", 35);
	return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	if(random(2))	return;

	if((int)me->query_skill("guangming-jian", 1) < 60
	|| me->query("combat_exp") < 100000)	return;

	me->reset_action();

	COMBAT_D->do_attack(me, victim, me->query_temp("weapon"));
}

int enable_factor() { return 17; }

int learn_bonus() { return 14; }

int practice_bonus() { return 13; }

int study_bonus() { return 14; }