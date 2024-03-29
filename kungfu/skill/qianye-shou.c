// qianye-shou.c -如来千叶手
inherit SKILL;
mapping *action = ({
([  "action" : "$N一式「"+BLU+"南海礼佛"+NOR+"」，右手虚晃，左手扬起，突然拍向$n的背后二穴",
    "force" : 100,
    "lvl" : 0,
    "skill_name" : BLU "南海礼佛" NOR,
    "damage_type" : "瘀伤"
]),
([  "action" : "$N侧身一晃，一式「"+YEL+"金玉瓦砾"+NOR+"」，左手拿向$n的肩头，右拳打向$n的胸口",
    "force" : 110,
    "lvl" : 13,
    "skill_name" : YEL "金玉瓦砾" NOR,
    "damage_type" : "瘀伤"
]),
([  "action" : "$N一式「"+RED+"人命呼吸"+NOR+"」，右手环拢成爪，一出手就向扣$n的咽喉要害",
    "force" : 130,
    "lvl" : 25,
    "skill_name" : RED "人命呼吸" NOR,
    "damage_type" : "瘀伤"
]),
([  "action" : "$N左手虚招，右掌直立，一式「"+HIW+"镜里观影"+NOR+"」，错步飘出，疾拍$n的面门",
    "force" : 160,
    "lvl" : 37,
    "skill_name" : HIW "镜里观影" NOR,
    "damage_type" : "瘀伤"
]),
([  "action" : "$N使一式「"+BLU+"水中捉月"+NOR+"」，左拳上格，右手探底突出，抓向$n的裆部",
    "force" : 200,
    "lvl" : 50,
    "skill_name" : BLU "水中捉月" NOR,
    "damage_type" : "瘀伤"
]),
([  "action" : "$N双拳挥舞，一式「"+HIB+"浮云去来"+NOR+"」，两手环扣，拢成圈状，猛击$n的下颌",
    "force" : 250,
    "lvl" : 63,
    "skill_name" : HIB "浮云去来" NOR,
    "damage_type" : "内伤"
]),
([  "action" : "$N一式「"+BLU+"水泡出没"+NOR+"」，十指伸缩，虚虚实实地袭向$n的全身要穴",
    "force" : 310,
    "lvl" : 76,
    "skill_name" : BLU "水泡出没" NOR,
    "damage_type" : "内伤"
]),
([  "action" : "$N双手抱拳，一式「"+HIB+"想入飞飞"+NOR+"」，掌影翻飞，同时向$n施出九九八十一招",
    "force" : 380,
    "lvl" : 88,
    "skill_name" : HIB "想入飞飞" NOR,
    "damage_type" : "内伤"
]),
([  "action" : "$N一式「"+GRN+"觉后空空"+NOR+"」，拳招若隐若现，若有若无，缓缓地拍向$n的丹田",
    "force" : 460,
    "lvl" : 100,
    "skill_name" : GRN "觉后空空" NOR,
    "damage_type" : "内伤"
]),
});
int valid_enable(string usage) { return usage=="hand" || usage=="parry"; }

int practice_level(){   return 100;  }

int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("练如来千叶手必须空手。\n");
    if ((int)me->query("max_neili") < 100)
        return notify_fail("你的内力太弱，无法学如来千叶手。\n");
if (me->query_skill("hand", 1) <=me->query_skill("qianye-shou", 1))
        return notify_fail("你的基础不够，无法领会更高深的技巧。\n");
    if ((int)me->query_skill("hunyuan-yiqi", 1) < 20)
    if ((int)me->query_skill("yijing-force", 1) < 20)
    if ((int)me->query_skill("jiuyang-shengong", 1) < 20)
    if ((int)me->query_skill("taiji-shengong", 1) < 20)
        return notify_fail("你的禅宗气功火候不够，无法学如来千叶手。\n");

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
    level   = (int) me->query_skill("qianye-shou", 1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action = action[NewRandom(i, 20, level/5)];
                        break;
                }
    a_action["dodge"]  = 0-level*2;
    a_action["parry"]  = 0-level;
    a_action["attack"]  = level;
    a_action["damage"] = level;
    return a_action;

}
int practice_skill(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("练如来千叶手必须空手。\n");
    if ((int)me->query("qi") < 30)
        return notify_fail("你的体力太低了。\n");
    if ((int)me->query("neili") < 20)
        return notify_fail("你的内力不够练如来千叶手。\n");
    me->receive_damage("qi", 25);
    me->add("neili", -5);
    return 1;
}
