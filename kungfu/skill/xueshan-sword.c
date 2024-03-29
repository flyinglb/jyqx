// xueshan-sword 雪山剑法
#include <ansi.h>
inherit SKILL;  
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

mapping *action = ({
([      "action":"$N左手$w轻送，一招"+(order[random(13)])+"「朝天势」"NOR"向前刺出,疾刺$n的$l",
        "force" : 50,
        "dodge" : -10, 
        "damage": 200,
        "lvl" : 0,
        "skill_name" : "朝天势",
        "damage_type":  "刺伤"
]),
([      "action":"$N疾步上前，剑尖连连点出，一式"+(order[random(13)])+"「天雪九点」"NOR"，$n正瞧得眼花缭乱，手忙足乱之际，\n突然间$l被一剑刺中",
        "force" : 50,
        "dodge" : -10,
        "damage": 220,
        "lvl" : 7,
        "skill_name" : "天雪九点",
        "damage_type":  "刺伤"

]),
([      "action":"$N剑尖倏地翻上，斜刺$n的$l，正是雪山派剑法中的"+(order[random(13)])+"「老枝横斜」"NOR"",
        "force" : 70,
        "dodge" : -7,
        "damage": 250,
        "lvl" : 14,
        "skill_name" : "老枝横斜",
        "damage_type":  "刺伤"

]),
([      "action":"$N剑尖一抖，正当$n意欲招架，$N不再和他兵刃相碰，立时变招，带转剑锋，\n斜削敌喉，正是雪山派剑法中的"+(order[random(13)])+"「雪泥鸿爪」"NOR"",
        "force" : 80,
        "dodge" : -5,
        "damage": 300,
        "lvl" : 21,
        "skill_name" : "雪泥鸿爪",
        "damage_type":  "刺伤"

]),
([      "action":"$N手中$w一招"+(order[random(13)])+"「暗香疏影」"NOR"，如流光逸影，剑刃若有若无，斜削过来，$n难以抵挡，被一剑削中$l",
        "force" : 100,
        "dodge" : -5, 
        "parry" : 10,
        "damage": 320,
        "lvl" : 28,
        "skill_name" : "暗香疏影",
        "damage_type":  "割伤"

]),


([      "action":"$N手中$w连划五个圈子，一招"+(order[random(13)])+"「朔风忽起」"NOR"，五道剑芒如罡风呼啸，向$n疾刮而去",
        "force" : 100,
        "dodge" : -5, 
        "parry" : 10,
        "damage": 350,
        "lvl" : 35,
        "skill_name" : "朔风忽起",
        "damage_type":  "割伤"

]),
([      "action":"$N一式"+(order[random(13)])+"「明驼西来」"NOR"，手中$w看似沉滞不堪，却似慢实快，令$n难断虚实，无可躲避",
        "force" : 110,
        "dodge" : -5,
        "parry" : 10, 
        "damage": 380,
        "lvl" : 42,
        "skill_name" : "明驼西来",
        "damage_type":  "刺伤"

]),

([      "action":"$N忽然收剑回划，一式"+(order[random(13)])+"「飞沙走石」"NOR"，猛地激起地上落叶飞石四处飞扬，挟无比威势，向$n$l刺去",
        "force" : 120,
        "dodge" : -5,
        "parry" : 10, 
        "damage": 400,
        "lvl" : 49,
        "skill_name" : "飞沙走石",
        "damage_type":  "刺伤"

]),
([      "action":"$N举剑和身跃出，一式"+(order[random(13)])+"「胡马越岭」"NOR"，$w幻出万道剑芒，于剑光中疾取$n的$l",
        "force" : 150,
        "dodge" : 0,
        "damage": 420,
        "lvl" : 56,
        "skill_name" : "胡马越岭",
       "damage_type":  "刺伤"

]),


([      "action":"$N左手紧握剑指，右剑默运冰雪心法，剑上隐隐青气透出，一式"+(order[random(13)])+"「岭上双梅」"NOR"，\n剑指剑锋左右夹攻，直逼$n$l",
        "force" : 180,
        "dodge" : 0,
        "damage": 450,
        "lvl" : 63,
        "skill_name" : "岭上双梅",
       "damage_type":  "刺伤"

]),
([      "action":"$N一式"+(order[random(13)])+"「明月羌笛」"NOR"，$w划了一个半月弧形，洒出点点银光，飞向$n的$l",
        "force" : 200,
        "dodge" : 5,
        "damage": 480,
        "lvl" : 70,
        "skill_name" : "明月羌笛",
        "damage_type":  "刺伤"

]), 
([      "action":"$N一招"+(order[random(13)])+"「月色黄昏」"NOR"，使得若有若无，朦朦胧胧，$w斜斜划出，直取$n$l",
        "force" : 220,
        "dodge" : 5,
        "parry" : 10,
        "damage": 500,
        "lvl" : 77,
        "skill_name" : "月色黄昏",
        "damage_type":  "刺伤"

]), 
([      "action":"$N手中$w抖动，一招"+(order[random(13)])+"「梅雪争春」"NOR"，虚中有实，实中有虚，剑尖剑锋齐用，\n剑尖是雪点，剑锋乃格枝，四面八方的向$n攻了过来",
        "force" : 250,
        "dodge" : 5,
        "damage": 520,
        "lvl" : 84,
        "skill_name" : "梅雪争春",
        "damage_type":  "刺伤"

]), 

([      "action":"$N手中$w甩出，一招"+(order[random(13)])+"「鹤飞九天」"NOR"，在空中盘旋回饶，如闪电般向$n刺出九九\n八十一剑，然后飞回$N手中",
        "force" : 300,
        "dodge" : 5,
        "damage": 550,
        "lvl" : 91,
        "skill_name" : "鹤飞九天",
        "damage_type":  "刺伤"

]), 
([      "action":"$N长啸一声，身法加快，一招"+(order[random(13)])+"「暗影浮香」"NOR"，$w如梅干弯弯递出，$n正惊疑间，\n剑上突然豪光绽放,道道剑气向$n笼罩而去",
        "force" : 350,
        "dodge" : 5,
        "damage": 600,
        "lvl" : 100,
        "skill_name" : "暗影浮香",
        "damage_type":  "刺伤"

]),
});

int valid_learn(object me)
{
    object ob;
    if( (int)me->query("max_neili") < 50 )
        return notify_fail("你的内力不够，没有办法练雪山剑法。\n");
   if( (string)me->query_skill_mapped("force")!= "bingxue-xinfa")
        return notify_fail("雪山剑法必须配合冰雪心法才能练。\n");
    if( !(ob = me->query_temp("weapon"))
    ||      (string)ob->query("skill_type") != "sword" )
        return notify_fail("你必须先找一把剑才能练剑法。\n");

    return 1;
}

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }

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
        level   = (int) me->query_skill("xueshan-sword",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if( (int)me->query("qi") < 20
        ||      (int)me->query("neili") < 10 )
                return notify_fail("你的内力或气不够，没有办法练习雪山剑法。\n");
        me->receive_damage("qi", 15);
        me->add("neili", -5);
        write("你按著所学练了一遍雪山剑法。\n");
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"xueshan-sword/" + action;
}

