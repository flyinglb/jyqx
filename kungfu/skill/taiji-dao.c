// taiji-dao.c 太极刀
// cleansword 2/15/96
inherit SKILL;
mapping *action = ({
([  "action" : "$N手中$w斜指，一招「"+HIW+"停车问路"+NOR+"」，反身一顿，一刀向$n的$l撩去",
    "force" : 120,
    "damage_type" : "割伤"
]),
([  "action" : "$N一招「"+HIM+"童子挂画"+NOR+"」，左右腿虚点，$w一提一收，平刃挥向$n的颈部",
    "force" : 130,
    "damage_type" : "割伤"
]),
([  "action" : "$N展身虚步，提腰跃落，一招「"+HIG+"推窗望月"+NOR+"」，刀锋一卷，拦腰斩向$n",
    "force" : 140,
    "damage_type" : "割伤"
]),
([  "action" : "$N一招「"+HIR+"开门见山"+NOR+"」，$w大开大阖，自上而下划出一个大弧，笔直劈向$n",
    "force" : 160,
    "damage_type" : "割伤"
]),
([  "action" : "$N手中$w一沉，一招「"+HIY+"临溪观鱼"+NOR+"」，双手持刃拦腰反切，砍向$n的胸口",
    "force" : 180,
    "damage_type" : "割伤"
]),
([  "action" : "$N挥舞$w，使出一招「"+WHT+"张弓望的"+NOR+"」，上劈下撩，左挡右开，齐齐罩向$n",
    "force" : 210,
    "damage_type" : "割伤"
]),
([  "action" : "$N一招「"+HIC+"风送轻舟"+NOR+"」，左脚跃步落地，$w顺势往前，挟风声劈向$n的$l",
    "force" : 240,
    "damage_type" : "割伤"
]),
([  "action" : "$N盘身驻地，一招「"+HIB+"川流不息"+NOR+"」，挥出一片流光般的刀影，向$n的全身涌去",
    "force" : 280,
    "damage_type" : "割伤"
]),
});

int valid_enable(string usage) { return (usage == "blade") || (usage == "parry"); }
int practice_level(){   return 60;  }
int valid_learn(object me)
{
    if ((int)me->query("max_neili") < 100)
        return notify_fail("你的内力不够。\n");
    if ((int)me->query_skill("taiji-shengong", 1) < 20)
    if ((int)me->query_skill("yijing-force", 1) < 20)
        return notify_fail("你的太极神功火候太浅。\n");
    if ((int)me->query_skill("taiji-quan", 1) < 20)
        return notify_fail("你的太极拳火候太浅。\n");
    if (me->query_skill("blade", 1) <=me->query_skill("taiji-dao", 1))
        return notify_fail("你的基础不够，无法领会更高深的技巧。\n");
    return 1;
}
mapping query_action(object me, object weapon)
{
    mapping a_action;
    int i, level;
    level   = (int) me->query_skill("taiji-dao", 1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action = action[NewRandom(i, 20, level/5)];
                        break;
                }
    a_action["dodge"]  = 0-level/3;
    a_action["parry"]  = 0-level/2;
    a_action["attack"]  = level/2;
    a_action["damage"] = level;
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
        return notify_fail("你的体力不够练太极刀法。\n");
    me->receive_damage("qi", 30);
    return 1;
}
string perform_action_file(string action)
{
        return __DIR__"taiji-dao/" + action;
}

