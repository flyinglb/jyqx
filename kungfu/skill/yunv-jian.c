// yunv-jian.c 玉女剑

inherit SKILL;

mapping *action = ({
([      "action" : "$N一招「雁行斜击」，身形斜飞，手中$w轻轻点向$n的$l",
        "force" : 60,
        "dodge" : 20,
        "parry" : 10,
        "damage" : 35,
        "lvl" : 0,
        "damage_type" : "刺伤"
]),
([      "action" : "$N长跃而起，「白虹经天」，$w猛然下刺",
        "force" : 70,
        "dodge" : 15,
        "parry" : 10,
        "damage" : 40,
        "lvl" : 4,
        "damage_type" : "刺伤"
]),
([      "action" : "$N使出「浪迹天涯」，挥剑直劈，威不可当",
        "force" : 80,
        "dodge" : 15,
        "parry" : 10,
        "damage" : 45,
        "lvl" : 9,
        "damage_type" : "内伤"
]),
([      "action" : "$N使「花前月下」一招自上而下搏击，模拟冰轮横空、清光铺地的光
景",
        "force" : 90,
        "dodge" : 15,
        "parry" : 10,
        "damage" : 50,
        "lvl" : 14,
        "damage_type" : "刺伤"
]),
([      "action" : "$N手中$w颤动，如鲜花招展来回挥削，只幌得$n眼花撩乱，浑不知从
何攻来",
        "force" : 100,
        "dodge" : 15,
        "parry" : 15,
        "damage" : 55,
        "lvl" : 19,
        "damage_type" : "内伤"
]),
([      "action" : "$N使出「清饮小酌」剑柄提起，剑尖下指，有如提壶斟酒，直挥$n的
$l",
        "force" : 110,
        "dodge" : 15,
        "parry" : 15,
        "damage" : 60,
        "lvl" : 24,
        "damage_type" : "刺伤"
]),
([      "action" : "$N手中$w由内自外一刺，左手如斟茶壶，使出「扫雪烹茶」来",
        "force" : 120,
        "dodge" : 10,
        "parry" : 15,
        "damage" : 65,
        "lvl" : 29,
        "damage_type" : "刺伤"
]),
([      "action" : "$N左掌横摆胸前，右手中$w轻轻挥拂，却是一招「抚琴按萧」",
        "force" : 130,
        "dodge" : 15,
        "parry" : 15,
        "damage" : 70,
        "lvl" : 34,
        "damage_type" : "刺伤"
]),
([      "action" : "$N一招「松下对弈」，$w自右向左挥一个大弧，刺向$n的$l",
        "force" : 140,
        "dodge" : 15,
        "parry" : 15,
        "damage" : 75,
        "lvl" : 39,
        "damage_type" : "刺伤"
]),
([      "action" : "$N左手如拂五弦，竟以掌为剑攻向$n，却是一招「池边调鹤」",
        "force" : 150,
        "dodge" : 10,
        "parry" : 20,
        "damage" : 80,
        "lvl" : 44,
        "damage_type" : "刺伤"
]),
([      "action" : "$N一招「柳絮风飘」，$w轻灵地划出几个圆弧，向$n的$l挥去",
        "force" : 160,
        "dodge" : 15,
        "parry" : 20,
        "damage" : 85,
        "lvl" : 49,
        "damage_type" : "刺伤"
]),
([      "action" : "$N一招「小园艺菊」，手中$w迅疾向$n的下盘连点三点",
        "force" : 170,
        "dodge" : 15,
        "parry" : 20,
        "damage" : 90,
        "lvl" : 54,
        "damage_type" : "刺伤"
]),
([      "action" : "$N使出「西窗夜话」，手中$w中宫直入，攻向$n的$l",
        "force" : 180,
        "dodge" : 15,
        "parry" : 20,
        "damage" : 95,
        "lvl" : 59,
        "damage_type" : "刺伤"
]),
([      "action" : "$N脚下左高右低，一招「柳荫联句」，$w在空中化成一道光环，急攻
$n",
        "force" : 190,
        "dodge" : 5,
        "parry" : 20,
        "damage" : 100,
        "lvl" : 64,
        "damage_type" : "内伤"
]),
([      "action" : "$N手中$w由下而上卷起，犹如打起竹帘一般，却是「竹帘临池」",
        "force" : 200,
        "dodge" : 15,
        "parry" : 20,
        "damage" : 105,
        "lvl" : 70,
        "damage_type" : "刺伤"
]),
([      "action" : "$N做搭弓射箭状，一招「木兰射雁」，右手$w直刺$n的$l",
        "force" : 210,
        "dodge" : 20,
        "parry" : 20,
        "damage" : 110,
        "lvl" : 76,
        "damage_type" : "刺伤"
]),
([      "action" : "$N左手剑诀一领，右手$w平平刺向$n的$l，是一招「双蝶迷回」",
        "force" : 220,
        "dodge" : 40,
        "parry" : 20,
        "damage" : 115,
        "lvl" : 82,
        "damage_type" : "刺伤"
]),
([      "action" : "$N手中$w合身疾刺，一招「孤云出釉」，直指$n的$l",
        "force" : 230,
        "dodge" : 30,
        "parry" : 20,
        "damage" : 120,
        "lvl" : 88,
        "damage_type" : "刺伤"
]),
([      "action" : "$N一招「幽兰空谷」，$w看似随意地一挥，从$n不可思议的角度攻入
",
        "force" : 240,
        "dodge" : 20,
        "parry" : 25,
        "damage" : 125,
        "lvl" : 94,
        "damage_type" : "刺伤"
]),
([      "action" : "$N使出「茶花满路」，一时间空中尽是$w的影子，令$n不知如何抵挡
",
        "force" : 250,
        "dodge" : 45,
        "parry" : 25,
        "damage" : 130,
        "lvl" : 100,
        "damage_type" : "刺伤"
]),
([      "action" : "$N一招「陌路采桑」，$w连点数点，疾刺$n的$l",
        "force" : 260,
        "dodge" : 35,
        "parry" : 25,
        "damage" : 135,
        "lvl" : 99,
        "damage_type" : "刺伤"
]),
([      "action" : "$N突然盘蹲下来，一招「秋雨萧萧」，$w自下而上刺向$n",
        "force" : 270,
        "dodge" : 25,
        "parry" : 25,
        "damage" : 140,
        "lvl" : 106,
        "damage_type" : "刺伤"
]),
([      "action" : "$N错开脚步，手中$w突然从自己的肋下刺出，却是一招「琴心剑胆」
",
        "force" : 280,
        "dodge" : 35,
        "parry" : 25,
        "damage" : 145,
        "lvl" : 112,
        "damage_type" : "刺伤"
]),
([      "action" : "$N犹如在水面滑行一般，一招「池塘秋夜」，平平地向$n的$l挥去",
        "force" : 290,
        "dodge" : 40,
        "parry" : 25,
        "damage" : 150,
        "lvl" : 118,
        "damage_type" : "刺伤"
]),
([      "action" : "$N一招「皓腕玉镯」，手中$w刺点$n的手腕",
        "force" : 300,
        "dodge" : 45,
        "parry" : 25,
        "damage" : 155,
        "lvl" : 124,
        "damage_type" : "刺伤"
]),
([      "action" : "$N一招「牡丹含泪」，$w绕出数个银圈，平平地向$n的$l卷去",
        "force" : 310,
        "dodge" : 45,
        "parry" : 25,
        "damage" : 160,
        "lvl" : 131,
        "damage_type" : "刺伤"
]),
([      "action" : "$N左脚轻点地面，身形往前一扑，一招「芍药蕴珠」，$w向$n的$l刺
去",
        "force" : 320,
        "dodge" : 45,
        "parry" : 30,
        "damage" : 165,
        "lvl" : 138,
        "damage_type" : "刺伤"
]),
([      "action" : "$N一招「檐前飞燕」，身形跃起，手中$w扫向$n的$l",
        "force" : 330,
        "dodge" : 45,
        "parry" : 30,
        "damage" : 165,
        "lvl" : 145,
        "damage_type" : "刺伤"
]),

([  "action" : "$N脸现黯然之色，随意一招「蒹葭苍苍」，$w刺向$n的$l",
        "force" : 380,
        "dodge" : 35,
        "parry" : 30,
        "damage" : 175,
        "lvl" : 159,
        "damage_type" : "刺伤"
]),
});


int valid_enable(string usage) { return (usage == "sword") || (usage == "parry")
; }

int valid_learn(object me)
{
        if ((int)me->query_skill("yunv-xinfa", 1) < 15)
                return notify_fail("你的玉女心法火候不到，无法学习玉女剑法。\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level   = (int) me->query_skill("yunv-jian",1);
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
        if ((int)me->query("qi") < 45)
                return notify_fail("你的体力不够练玉女剑法。\n");
        if ((int)me->query("neili") < 15)
                return notify_fail("你的内力不足以练玉女剑法。\n");
        me->receive_damage("qi", 26);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"yunv-jian/" + action;
}
