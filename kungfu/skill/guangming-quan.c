// guangming-quan - 大光明拳法

inherit SKILL;

mapping *action = ({
([	"action" : "$N一式「焚我残躯」，右手虚晃，左手扬起，突然拍向$n的$l",
	"force" : 100,
        "dodge" : 10,
	"lvl" : 0,
	"skill_name" : "焚我残躯",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N一式「熊熊圣火」，十指张开，举在胸前，作火焰飞腾之状，攻向$n",
	"force" : 110,
        "dodge" : 10,
        "parry" : 10,
        "damage" : 10,
	"lvl" : 10,
	"skill_name" : "熊熊圣火",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N侧身一晃，一式「生亦何欢」，左手拿向$n的肩头，右拳打向$n的胸口",
	"force" : 120,
        "dodge" : 15,
        "damage" : 15,
	"lvl" : 20,
	"skill_name" : "生亦何欢",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N一式「死亦何苦」，右手环拢成爪，一出手就向扣$n的咽喉要害",
	"force" : 130,
        "dodge" : 20,
	"damage": 15,
	"lvl" : 30,
	"skill_name" : "死亦何苦",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N左手虚招，右掌直立，一式「为善除恶」，错步飘出，疾拍$n的面门",
	"force" : 160,
        "dodge" : 20,
	"damage": 20,
	"lvl" : 40,
	"skill_name" : "为善除恶",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N使一式「惟光明故」，左拳上格，右手探底突出，抓向$n的$l",
	"force" : 200,
        "dodge" : 30,
	"damage": 25,
	"lvl" : 50,
	"skill_name" : "惟光明故",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N双拳挥舞，一式「喜乐悲愁」，两手环扣，拢成圈状，猛击$n的下颌",
	"force" : 250,
        "dodge" : 30,
	"damage": 30,
	"lvl" : 56,
	"skill_name" : "喜乐悲愁",
        "damage_type" : "内伤"
]),
([	"action" : "$N一式「皆归尘土」，十指伸缩，虚虚实实地袭向$n的全身要穴",
	"force" : 310,
        "dodge" : 40,
	"damage": 35,
	"lvl" : 62,
	"skill_name" : "皆归尘土",
        "damage_type" : "内伤"
]),
([	"action" : "$N双手抱拳，一式「怜我世人」，掌影翻飞，同时向$n施出九九八十一招",
	"force" : 380,
        "dodge" : 40,
	"damage": 40,
	"lvl" : 68,
	"skill_name" : "怜我世人",
        "damage_type" : "内伤"
]),
([	"action" : "$N一式「忧患实多」，拳招若隐若现，若有若无，缓缓地拍向$n的丹田",
	"force" : 460,
        "dodge" : 40,
	"damage": 50,
	"lvl" : 74,
	"skill_name" : "忧患实多",
        "damage_type" : "内伤"
]),
});

int valid_enable(string usage) { return usage=="unarmed" || usage=="parry"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练大光明拳必须空手。\n");
	if ((int)me->query_skill("sunforce", 1) < (int)me->query_skill("guangming-quan", 1) 
		&& me->query_skill("guangming-quan", 1) > 60 )
		return notify_fail("你的光明神功火候不够，无法学更高深的大光明拳。\n");
	if ((int)me->query("max_force") < 100)
		return notify_fail("你的内力太弱，无法练大光明拳。\n");
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
	level   = (int) me->query_skill("guangming-quan",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[random(i)];
}

int practice_skill(object me)
{
	if ((int)me->query("kee") < 30)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("force") < 20)
		return notify_fail("你的内力不够练大光明拳。\n");
	me->receive_damage("kee", 25);
	me->add("force", -5);
	return 1;
}

int enable_factor() { return 15; }

int learn_bonus() { return 15; }

int practice_bonus() { return 13; }

int study_bonus() { return 15; }