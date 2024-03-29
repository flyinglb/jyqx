// taiji-jian.c 太极剑
// cleansword 2/15/96
// Marz 5/21/96
inherit SKILL;
mapping *action = ({
([  "action" : "$N虚步提腰，一招「"+HIM+"蜻蜓点水"+NOR+"」，手中$w轻轻颤动，一剑剑点向$n的$l",
    "force" : 60,
    "lvl" : 0,
    "damage_type" : "刺伤"
]),
([  "action" : "$N向前跨上一步，左手剑诀，右手$w使出一式「"+YEL+"指南针"+NOR+"」直刺$n的$l",
    "force" : 70,
    "lvl" : 10,
    "damage_type" : "刺伤"
]),
([  "action" : "$N身形往右一挫，左手剑诀，右手$w使出一式「"+WHT+"大魁星"+NOR+"」刺向$n的$l",
    "force" : 80,
    "lvl" : 15,
    "damage_type" : "刺伤"
]),
([  "action" : "$N双膝下沉，右手$w使出一式「"+BLU+"探海式"+NOR+"」，由下而上疾刺$n的$l",
    "force" : 90,
    "lvl" : 26,
    "damage_type" : "刺伤"
]),
([  "action" : "$N一招「"+HIW+"燕子掠波"+NOR+"」，$w自上而下划出一个大弧，平平地向$n的$l挥去",
    "force" : 100,
    "lvl" : 37,
    "damage_type" : "刺伤"
]),
([  "action" : "$N上身往左侧一拧，一招「"+BLK+"乌龙摆尾"+NOR+"」，右手$w反手向$n的$l挥去",
    "force" : 110,
    "lvl" : 48,
    "damage_type" : "刺伤"
]),
([  "action" : "$N一招「"+RED+"右"+NOR+"拦扫」，一招「"+RED+"左"+NOR+"拦扫」，剑锋平指，一气呵成横扫$n的$l",
    "force" : 120,
    "lvl" : 50,
    "damage_type" : "刺伤"
]),
([  "action" : "$N左腿提膝，手中$w斜指，一招「"+HIC+"宿鸟投林"+NOR+"」刺向$n的$l",
    "force" : 130,
    "lvl" : 60,
    "damage_type" : "刺伤"
]),
([  "action" : "$N一招「"+CYN+"青龙出水"+NOR+"」，$w自下而上划出一个大弧，平平地挥向$n的$l",
    "force" : 140,
    "lvl" : 70,
    "damage_type" : "刺伤"
]),
([  "action" : "$N使出「"+RED+"三"+NOR+"环套"+HIW+"月"+NOR+"」，$w划出三个圆圈，剑锋直出，绵绵不断划向$n的$l",
    "force" : 150,
    "lvl" : 80,
    "damage_type" : "刺伤"
]),
([  "action" : "$N一招「"+MAG+"风卷荷叶"+NOR+"」，$w轻灵地划出几个圆弧，迅速地向$n的$l挥去",
    "force" : 160,
    "lvl" : 100,
    "damage_type" : "刺伤"
]),
([  "action" : "$N一招「"+YEL+"虎抱头"+NOR+"」，$w划出一个左低右高的大弧，斜斜地斩向$n的$l",
    "force" : 170,
    "lvl" : 120,
    "damage_type" : "刺伤"
]),
([  "action" : "$N使出「"+HIR+"狮子摇头"+NOR+"」，$w由右向左划出一个大８字，将$n圈在其中",
    "force" : 180,
    "lvl" : 141,
    "damage_type" : "刺伤"
]),
([  "action" : "$N左脚踏实，右脚虚点，一招「"+HIW+"仙人指路"+NOR+"」，右手$w带着一团剑花，逼向$n的$l",
    "force" : 190,
    "lvl" : 162,
    "damage_type" : "刺伤"
]),
([  "action" : "$N轻轻跃起，一招「"+CYN+"野马跳涧"+NOR+"」，$w在半空中化为一圈银芒，落向$n的$l",
    "force" : 200,
    "lvl" : 184,
    "damage_type" : "刺伤"
]),
([  "action" : "$N两腿前箭后弓，一招「"+HIR+"射雁式"+NOR+"」，右手$w直刺$n的$l",
    "force" : 210,
    "lvl" : 205,
    "damage_type" : "刺伤"
]),
([  "action" : "$N一招「"+WHT+"小魁星"+NOR+"」，身形往左一挫，左手剑诀，右手$w平平地向$n的$l挥去",
    "force" : 220,
    "lvl" : 226,
    "damage_type" : "刺伤"
]),
([  "action" : "$N猱身扑上，一招「"+HIW+"白猿献果"+NOR+"」，手中$w斜斜地向$n的$l挥去",
    "force" : 230,
    "lvl" : 248,
    "damage_type" : "刺伤"
]),
([  "action" : "$N一招「"+RED+"迎风掸尘"+NOR+"」，$w看似随意地一挥，$n却陡觉一股劲气迎面袭来。",
    "force" : 240,
    "lvl" : 260,
    "damage_type" : "刺伤"
]),
([  "action" : "$N一招「"+YEL+"顺水推舟"+NOR+"」，$w自上而下划出一个大弧，平平地向$n的$l挥去。",
    "force" : 250,
    "lvl" : 281,
    "damage_type" : "刺伤"
]),
([  "action" : "$N一招「"+WHT+"流星赶月"+NOR+"」，$w疾刺$n的$l",
    "force" : 260,
    "lvl" : 300,
    "damage_type" : "刺伤"
]),
([  "action" : "$N突然盘蹲下身来，一招「"+BLU+"海底捞月"+NOR+"」，$w自下而上地向$n的$l挥去",
    "force" : 270,
    "lvl" : 325,
    "damage_type" : "刺伤"
]),
([  "action" : "$N一招「"+HIG+"挑帘式"+NOR+"」，$w自下而上徐徐划出一个大弧，平平地向$n的$l挥去",
    "force" : 280,
    "lvl" : 346,
    "damage_type" : "刺伤"
]),
([  "action" : "$N一招「"+YEL+"黄蜂入洞"+NOR+"」，$w自上而下划出一个大弧，平平地向$n的$l挥去",
    "force" : 290,
    "lvl" : 367,
    "damage_type" : "刺伤"
]),
([  "action" : "$N一招「"+WHT+"大鹏展翅"+NOR+"」，身形跃起，右手$w刺向$n的$l",
    "force" : 300,
    "lvl" : 380,
    "damage_type" : "刺伤"
]),
([  "action" : "$N一招「"+BLK+"车轮剑"+NOR+"」，$w化作一片银盘，平平地向$n的$l卷去",
    "force" : 310,
    "lvl" : 390,
    "damage_type" : "刺伤"
]),
([  "action" : "$N左脚轻点地面，身形往前一扑，一招「"+BLU+"天马行空"+NOR+"」，$w向$n的$l挥去",
    "force" : 320,
    "lvl" : 400,
    "damage_type" : "刺伤"
]),
([  "action" : "$N一招「"+WHT+"风扫梅花"+NOR+"」，身体跃在半空，手中$w扫向$n的$l",
    "force" : 330,
    "lvl" : 410,
    "damage_type" : "刺伤"
]),
([  "action" : "$N一招「"+HIC+"却步抽剑"+NOR+"」，左脚跃步落地，$w回抽，反手勾向$n的$l",
    "force" : 340,
    "lvl" : 430,
    "damage_type" : "刺伤"
]),
([  "action" : "$N右腿半屈般蹲，一招「"+WHT+"如封似闭"+NOR+"」，剑尖虚指，转身撩向$n的$l",
    "force" : 350,
    "lvl" : 440,
    "damage_type" : "刺伤"
]),
([  "action" : "$N回身拧腰，右手虚抱，一招「"+HIY+"拨云瞻日"+NOR+"」，$w中宫直进，刺向$n的$l",
    "force" : 380,
    "lvl" : 450,
    "damage_type" : "刺伤"
]),
});

int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }
int practice_level(){   return 145;  }
int valid_learn(object me)
{
    object weapon;
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "sword")
    if (!objectp(weapon = me->query_temp("secondary_weapon"))
    || (string)weapon->query("skill_type") != "sword")
        return notify_fail("你必须先找把剑才能学太极剑法。\n");

    if ((int)me->query("max_neili") < 100)
        return notify_fail("你的内力不够。\n");
    if ((int)me->query_skill("taiji-shengong", 1) < 60 )
        return notify_fail("你的太极神功火候太浅。\n");
    if ((int)me->query_skill("taiji-quan", 1) <= me->query_skill("taiji-jian", 1))
    if ((int)me->query_skill("taiji-quan", 1) < 100 )
        return notify_fail("你的太极拳火候太浅。\n");
    if (me->query_skill("sword", 1) <=me->query_skill("taiji-jian", 1))
        return notify_fail("你的基础不够，无法领会更高深的技巧。\n");
    return 1;
}
mapping query_action(object me, object weapon)
{
    mapping a_action;
    int i, level;
    level   = (int) me->query_skill("taiji-jian", 1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action = action[NewRandom(i, 20, level/5)];
                        break;
                }
    a_action["dodge"]  = 0-level/3;
    a_action["parry"]  = 0-level/3;
    a_action["attack"]  = level/2;
    a_action["damage"] = level/2;
    return a_action;

}
int practice_skill(object me)
{
    object weapon;
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "sword")
    if (!objectp(weapon = me->query_temp("secondary_weapon"))
    || (string)weapon->query("skill_type") != "sword")
        return notify_fail("你使用的武器不对。\n");
    if ((int)me->query("qi") < 50)
        return notify_fail("你的体力不够练太极剑法。\n");
    me->receive_damage("qi", 30);
    return 1;
}
string perform_action_file(string action)
{
    return __DIR__"taiji-jian/" + action;
}
