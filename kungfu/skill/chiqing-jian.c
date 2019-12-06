// chiqing-jian.c 痴情三圣剑
// Made by Robin

inherit SKILL;

mapping *action = ({
([      "action" : "$N漫步提腰，一招「"WHT"逍遥问路"NOR"」，飘然来至$n面前，随即手中$w微震，
剑尖疾点向$n的$l",
        "force" : 300,
        "dodge" : 20,
        "damage" : 60,
        "lvl" : 0,
        "damage_type" : "刺伤"
]),
([      "action" : "$N斜跨一步，使出一式「"YEL"情长儿女"NOR"」，挥剑舞出两道一长一短的光影
直刺$n的$l",
        "force" : 350,
        "dodge" : 15,
        "damage" : 70,
        "lvl" : 10,
        "damage_type" : "刺伤"
]),
([      "action" : "$N一招「"HIM"巍巍昆仑"NOR"」，$w骤然出鞘又立刻回到剑鞘中，随即转身翩然
离去。$n这时才感觉到有一股劲气逼向自己的$l",
        "force" : 400,
        "dodge" : 25,
        "damage" : 80,
        "lvl" : 20,
        "damage_type" : "刺伤"
]),
([      "action" : "$N双手举剑向天，一招「"HIY"峨峨华山"NOR"」，$w带起阵阵惊雷，自上而下向
$n的头颅剁去",
        "force" : 450,
        "dodge" : 10,
        "damage" : 90,
        "lvl" : 30,
        "damage_type" : "刺伤"
]),
([      "action" : "$N施展出「"MAG"千金一笑"NOR"」，手握$w颔首微微一笑，$n只看得一呆，却见
一道剑影犹如龙游般袭向自己的$l，而自己却没看清$N何时出的手！！",
        "force" : 500,
        "dodge" : 20,
        "damage" : 100,
        "lvl" : 40,
        "damage_type" : "刺伤"
]),
([      "action" : "$N左脚踏实，右脚虚点，一招「"CYN"琴短箫长"NOR"」，$w带着一团剑花，飘浮
不定地逼向$n的$l",
        "force" : 550,
        "dodge" : 5,
        "damage" : 110,
        "lvl" : 50,
        "damage_type" : "刺伤"
]),
([      "action" : "$N一招「"RED"天涯思君"NOR"」，左手轻抚$w，随即猛地一弹，右手向前一递，
只见一道闪烁不定的剑影迅速刺向$n的$l",
        "force" : 590,
        "dodge" : 5,
        "damage" : 120,
        "lvl" : 60,
        "damage_type" : "刺伤"
]),
([      "action" : "$N回身低首，神色黯然，一招「"GRN"别样情怀"NOR"」，$w剑尖游移不定地刺向
$n的$l",
        "force" : 620,
        "dodge" : -5,
        "damage" : 140,
        "lvl" : 70,
        "damage_type" : "刺伤"
]),
([      "action" : "$N坐手掩面，一招「"HIW"鹊桥无期"NOR"」，右手$w斜向下划出，$n微觉奇怪，正迟
疑间，却见$N手中的$w已反挑而上，直刺自己的咽喉",
        "force" : 660,
        "dodge" : 5,
        "damage" : 160,
        "lvl" : 80,
        "damage_type" : "刺伤"
]),
([  "action" : "$N忽然面露微笑，一招「"HIG"霓裳轻舞"NOR"」，右手$w一闪，舞出三团剑花刺向$n
的上中下三路",
        "force" : 720,
        "dodge" : -5,
        "damage" : 180,
        "lvl" : 90,
        "damage_type" : "刺伤"
]),
([      "action" : "$N左手食指疾点$w，一招「"HIB"君子好逑"NOR"」，$w发出一声龙吟，余音缭绕，$n
只觉得的胸前一闷，一阵刚猛的劲气迫向自己",
        "force" : 780,
        "dodge" : -5,
        "damage" : 200,
        "lvl" : 100,
        "damage_type" : "刺伤"
]),
([      "action" : "$N右手微震，一招「"HIC"考般在陆"NOR"」，手中$w急颤，发出一阵震耳欲聋的轰鸣，
刹那间飞沙走石，$n已在一团剑光的笼罩下，正勉力支撑着",
        "force" : 840,
        "dodge" : 15,
        "damage" : 220,
        "lvl" : 110,
        "damage_type" : "刺伤"
]),
});


int valid_enable(string usage) { return (usage == "sword") || (usage == "parry")
; }

int valid_learn(object me)
{
    if (((int)me->query("max_neili") < 1000) ||
        ((int)me->query_skill("xuantian-force", 1) < 150))
       return notify_fail("你功力不到，无法学习痴情三圣剑。\n");
    return 1;
}

mapping query_action(object me, object weapon)
{
    int i, level;
    level   = (int) me->query_skill("chiqing-jian",1);
    for(i = sizeof(action); i > 0; i--)
    if(level > action[i-1]["lvl"])
        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
    object weapon;

    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "sword")
       return notify_fail("你使用的武器不对。\n");
    if ((int)me->query("qi") < 80)
       return notify_fail("你的体力不够练痴情三圣剑。\n");
    me->receive_damage("qi", 50);
    return 1;
}

string perform_action_file(string action)
{
    return __DIR__"chiqing-jian/" + action;
}
