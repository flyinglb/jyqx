// killsword.c 杀手剑
// by unix 1998.12
#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action":HIB"
$N强压住剑上枉死的冤魂，一阵阵杀气夺剑而出，将$n困在剑幕之中，$N轻送剑端\n"NOR+
HIW"一道白光一闪即失，$N手中的$w"NOR+HIW"已夺向$n的周身死穴！\n"NOR,
        "force" : 320,
        "dodge" : 0,
        "damage": 20,
        "lvl" : 0,
        "skill_name" : "夺魂破索",
        "damage_type":  "割伤"
]),
([      "action" : HIB"
$N掌剑怒视$n，突然明白了这非剑之招，手中$w"NOR+HIB"在空中左突右攻\n"NOR+
HIB"你狂哮一声：发出至阴至及的一招杀手，顿时令$n忙于奔命！\n"NOR,
        "force" : 340,
            "dodge" : 10,
        "damage": 25,
        "lvl" : 9,
        "skill_name" : "无影无心",
        "damage_type":  "割伤"
]),
([      "action" : HIB"
$N暗自摧动心魔，将枉死于剑上的无数冤魂，摧出体外，顿时阵阵杀气化做魔兽\n"NOR+
RED"血食$n，$n被魔兽吸干了七魂八魄，混身上下鲜血直流！\n"NOR,
        "force" : 360,
           "dodge" : 5,
        "damage" : 40,
        "lvl" : 18,
        "skill_name" : "食血魔兽",
        "damage_type":  "割伤"
]),
([      "action" : HIB"
$N轻叹古人，不知有己，而己矣不知有古人，顿时$N手中的$w"NOR+HIB"发出哀鸣...\n"
NOR+HIC"如清泉飞泄，大江东去，连绵不绝，在$n的周身急刺不止！\n"NOR,
        "force" : 380,
        "dodge" : 10,
        "damage" : 45,
        "lvl" : 27,
        "skill_name" : "大江东去",
        "damage_type":  "刺伤"
]),
([      "action" : HIW"
$N闭目仰望上天，大喝一声，手中的$w"NOR+HIW"如星雨飞泄，滚滚落下 $N发出了\n"NOR+
HIB"杀手剑之『殒石招唤』，顿时将$n逼退数步！\n"NOR,
        "force" : 420,
        "dodge" : 15,
        "damage": 55,
        "lvl" : 36,
                "skill_name" : "陨石招唤",
        "lvl" : 44,
        "damage_type": "刺伤",
]),
([      "action" : HIB"
$N突然领悟了师傅所传『杀手剑』之第三式「天兵招唤」手中$w"NOR+HIB"如飞瀑直泄\n"
NOR+HIC"$N掌剑望着$n有如天兵下凡，手中$w"NOR+HIC"化做无数分身直刺$n\n"NOR,
        "force" : 480,
        "dodge" : 5,
        "damage" : 55,
        "lvl" : 52,
        "skill_name" : "天兵招唤",
        "damage_type":  "刺伤"
]),
([      "action" : HIC"
$N突然领悟了师傅所传『杀手剑』之第二式「柔情蜜意」，$N双手合剑，往自身刺去\n"
NOR+HIC"$n一阵惊讹，只见眼前白光闪过，剑气已然逼目而来！\n"NOR,
        "force" : 500,
        "dodge" : 5,
        "damage": 65,
        "lvl" : 60,
        "skill_name" : "柔情蜜意",
        "damage_type":  "刺伤"
]),
([      "action" : HIC"
$N突然领悟了师傅所传『杀手剑』之第一式「冷若冰霜」，手中$w"NOR+HIC"顿时发出\n"
NOR+HIC"阵阵刺骨寒气，将$n的双手冻住，$N剑随心走直刺$n源穴！\n"NOR,
        "force" : 580,
        "dodge" : 10,
        "damage": 70,
        "lvl" : 70,
        "skill_name" : "冷若冰霜",
        "damage_type":  "刺伤"
]),
([      "action" : HIB"
$N抚剑长吟：恨吾不见古人，怨古人不见吾 $N怨气惯穿手中$w"NOR+HIB"口吐鲜血\n"NOR+
RED"顿时$N觉得魔性大发，剑不在手，剑摧人走， $N已拔握不住手中的$w"NOR+YEL"发出
\n"NOR+HIW"     『双十飞龙斩』\n"NOR,
        "force" : 580,
        "dodge" : 10,
        "damage": 80,
        "lvl" : 80,
        "skill_name" : "箫史乘龙",
        "damage_type":  "刺伤"
]),
([      "action" : HIW"
$N以气摧剑，神惯剑身，顿悟了『杀手剑』的绝学「气游百穴连绵不决」\n"NOR+
YEL"$N顿感真气有如大江奔腾，无穷无尽的向着白卉飞流东，$N大喝一声：\n"NOR+
HIY"    『三剑齐发』\n"NOR,

        "force" : 580,
        "dodge" : 15,
        "damage": 100,
        "lvl" : 90,
        "set_name" : "气游百穴",
        "damage_type":  "刺伤"
]),
([      "action" : HIB"
$N仰目归源，将剑上的杀气聚在剑端，目随心走，心随剑攻发出阵阵杀气摧剑而行\n"NOR+
HIC"杀得片地飞砂，乌云遮天，正所唯：吾不见风云初动，谁敢与剑争风！\n"NOR,
        "force" : 680,
        "dodge" : 15,
        "damage": 220,
        "lvl" : 114,
        "skill_name" : "风云终显",
        "damage_type":  "刺伤"
]),
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }
int valid_learn(object me)
{
me=this_player();
if(me->query_skill("force")<30)
return notify_fail("你的基本内功修为不够学杀手剑！\n");
if(me->query_skill("sword")<30)
return notify_fail("你的基本剑术不够学杀手剑！\n");
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
        level = (int) me->query_skill("killsword", 1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                return action[NewRandom(i, 20, level/50)];
}

int practice_skill(object me)
{
        object weapon;


        if(this_player()->query_skill("shenghuo-gong")<30)
        return notify_fail("你还要在圣火神功上有所加强！\n");
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");
        if ((int)me->query("qi") < 50)
        return notify_fail("你的体力不够练杀手剑！\n");
        me->receive_damage("qi", 25);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"killsword/" + action;
}

