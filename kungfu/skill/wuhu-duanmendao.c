// wuhu-duanmendao.c 五虎断门刀
inherit SKILL;
mapping *action = ({
([  "action" : "$N手中$w斜指，一招「"+RED+"直来直去"+NOR+"」，反身一顿，一刀向$n的$l撩去",
    "force" : 120,
    "damage_type" : "割伤"
]),
([  "action" : "$N一招「"+BLU+"童子挂画"+NOR+"」，左右腿虚点，$w一提一收，平刃挥向$n的颈部",
    "force" : 130,
    "damage_type" : "割伤"
]),
([  "action" : "$N展身虚步，提腰跃落，一招「"+HIW+"推窗望月"+NOR+"」，刀锋一卷，拦腰斩向$n",
    "force" : 140,
    "damage_type" : "割伤"
]),
([  "action" : "$N一招「"+WHT+"力劈华山"+NOR+"」，$w大开大阖，自上而下划出一个闪电，直劈向$n",
    "force" : 160,
    "damage_type" : "割伤"
]),
([  "action" : "$N手中$w一沉，一招「"+CYN+"临溪观鱼"+NOR+"」，双手持刃拦腰反切，砍向$n的胸口",
    "force" : 180,
    "damage_type" : "割伤"
]),
([  "action" : "$N挥舞$w，使出一招「"+MAG+"张弓望的"+NOR+"」，上劈下撩，左挡右开，齐齐罩向$n",
    "force" : 210,
    "damage_type" : "割伤"
]),
([  "action" : "$N一招「"+HIC+"风送轻舟"+NOR+"」，左脚跃步落地，$w顺势往前，挟风声劈向$n的$l",
    "force" : 240,
    "damage_type" : "劈伤"
]),
([  "action" : "$N盘身驻地，一招「"+HIB+"川流不息"+NOR+"」，挥出一片流光般的刀影，向$n的全身涌去",
    "force" : 280,
    "damage_type" : "刺伤"
]),
([  "action" : "$N右手后撤，手腕一翻，一招「"+YEL+"壮士断腕"+NOR+"」，顿时一道白光直斩向$n的手臂",
    "force" : 320,
    "damage_type" : "砍伤"
]),
([  "action" : "$N高高跃起，一招「"+HIY+"人头落地"+NOR+"」，手中$w直劈向$n的颈部",
    "force" : 320,
    "damage_type" : "劈伤"
]),
([  "action" : "$N贴地滑行，一招「"+RED+"断子绝孙"+NOR+"」，手中$w直撩去$n的裆部",
    "force" : 350,
    "damage_type" : "割伤"
]),
});

int valid_enable(string usage) { return (usage == "blade") || (usage == "parry"); }
int practice_level(){   return 140;  }
int valid_learn(object me)
{
//    if ((int)me->query_skill("wuhu-duanmendao", 1) > 120){
//       if (me->query("family/master_id")!="chen jin nan")
//        return notify_fail("五虎断门刀是陈近南所创，其他师傅参悟还来不及，怎能教你？\n");
//        }
    if ((int)me->query("max_neili") < 100)
        return notify_fail("你的内力不够。\n");
    if ((int)me->query_skill("blade", 1) < 20)
        return notify_fail("你的基本刀法火候太浅。\n");
    if (me->query_skill("blade", 1) <=me->query_skill("wuhu-duanmendao", 1))
        return notify_fail("你的基础不够，无法领会更高深的技巧。\n");
    return 1;
}
mapping query_action(object me, object weapon)
{
        mapping a_action;
        int i, level;
        level   = (int) me->query_skill("wuhu-duanmendao",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action=action[NewRandom(i, 20, level/5)];
                       break;
                 }
    if ( me->query_temp("perform_duan")) level+=level;
    a_action["dodge"]  = 0-level;
    a_action["parry"]  = 0-level*2;
    a_action["attack"]  = level;
    a_action["damage"] = level*4;
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
        return notify_fail("你的体力不够练五虎断门刀法。\n");
    me->receive_damage("qi", 30);
    return 1;
}
string perform_action_file(string action)
{
    return __DIR__"wuhu-duanmendao/" + action;
}
