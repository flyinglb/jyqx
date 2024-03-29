// banruo-zhang.c -般若掌
inherit SKILL;
mapping *action = ({
([  "action" : "$N前腿踢出，后腿脚尖点地，一式「"+RED+"横空出世"+NOR+"」，二掌直出，攻向$n的上中下三路",
    "force" : 150,
    "dodge" : -5,
    "damage_type" : "瘀伤",
    "lvl" : 0,
    "skill_name" :  RED "横空出世" NOR
]),
([  "action" : "$N左掌划一半圆，一式「"+MAG+"长虹贯日"+NOR+"」，右掌斜穿而出，疾拍$n的胸前大穴",
    "force" : 160,
    "dodge" : -10,
    "damage_type" : "瘀伤",
    "lvl" : 12,
    "skill_name" :  MAG "长虹贯日" NOR
]),
([  "action" : "$N使一式「"+HIW+"云断秦岭"+NOR+"」，右掌上引，左掌由后而上一个甩劈，斩向$n的$l",
    "force" : 170,
    "dodge" : -15,
    "damage_type" : "劈伤",
    "lvl" : 18,
    "skill_name" : HIW "云断秦岭" NOR
]),
([  "action" : "$N左掌护胸，右拳凝劲后发，一式「"+WHT+"铁索拦江"+NOR+"」，缓缓推向$n的$l",
    "force" : 185,
    "dodge" : -20,
    "damage_type" : "瘀伤",
    "lvl" : 24,
    "skill_name" : WHT "铁索拦江" NOR
]),
([  "action" : "$N使一式「"+HIB+"狂风卷地"+NOR+"」，全身飞速旋转，双掌一前一后，猛地拍向$n的胸口",
    "force" : 200,
    "dodge" : -25,
    "damage_type" : "瘀伤",
    "lvl" : 30,
    "skill_name" : HIB "狂风卷地" NOR
]),
([  "action" : "$N合掌抱球，猛吸一口气，一式「"+HIC+"怀中抱月"+NOR+"」，双掌疾推向$n的肩头",
    "force" : 220,
    "dodge" : -35,
    "damage_type" : "瘀伤",
    "lvl" : 36,
    "skill_name" : HIC "怀中抱月" NOR 
]),
([  "action" : "$N向上高高跃起，一式「"+CYN+"高山流水"+NOR+"」，居高临下，掌力笼罩$n的全身",
    "force" : 240,
    "dodge" : -60,
    "damage_type" : "瘀伤",
    "lvl" : 42,
    "skill_name" : CYN "高山流水" NOR
]),
([  "action" : "$N使一式「"+WHT+"摘星换斗"+NOR+"」，劲气弥漫，双掌如轮，一环环向$n的$l斫去",
    "force" : 270,
    "dodge" : -80,
    "damage_type" : "劈伤",
    "lvl" : 48,
    "skill_name" : WHT "摘星换斗" NOR
]),
([  "action" : "$N两掌上下护胸，一式「"+YEL+"翻江搅海"+NOR+"」，骤然化为满天掌雨，攻向$n",
    "force" : 310,
    "dodge" : -100,
    "damage_type" : "瘀伤",
    "lvl" : 54,
    "skill_name" : YEL "翻江搅海" NOR
]),
([  "action" : "$N一式「"+BLU+"金刚伏魔"+NOR+"」，双手合十，对着$n微微一揖，全身内劲如巨浪般汹涌而出",
    "force" : 360,
    "dodge" : -120,
    "damage_type" : "瘀伤",
    "lvl" : 60,
    "skill_name" : BLU "金刚伏魔" NOR
])
});
int practice_level(){   return 60;  }
int valid_enable(string usage) { return usage=="strike" ||  usage=="parry"; }
int valid_combine(string combo) { return combo=="yizhi-chan"; }
int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("练般若掌必须空手。\n");
    if ((int)me->query_skill("hunyuan-yiqi", 1) < 20)
    if ((int)me->query_skill("yijing-force", 1) < 20)
    if ((int)me->query_skill("jiuyang-shengong", 1) < 20)
    if ((int)me->query_skill("taiji-shengong", 1) < 20)
        return notify_fail("你的禅宗气功火候不够，无法学般若掌。\n");
    if ((int)me->query("max_neili") < 150)
        return notify_fail("你的内力太弱，无法练般若掌。\n");
    if (me->query_skill("unarmed", 1) <= me->query_skill("banruo-zhang", 1) 
    && me->query_skill("parry", 1) <= me->query_skill("banruo-zhang", 1) )
        return notify_fail("你的基本功火候未到，无法领会更高深的武功。\n");
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
    level = (int)me->query_skill("banruo-zhang", 1);
    for(i = sizeof(action); i > 0; i--)
        if(level > action[i-1]["lvl"])
            return action[NewRandom(i, 20, level/5)];
}
int practice_skill(object me)
{
    if ((int)me->query("qi") < 30)
        return notify_fail("你的体力太低了。\n");
    if ((int)me->query("neili") < 20)
        return notify_fail("你的内力不够练般若掌。\n");
    me->receive_damage("qi", 25);
    me->add("neili", -5);
    return 1;
}
