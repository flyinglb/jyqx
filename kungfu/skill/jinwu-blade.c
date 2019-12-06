// jinwu-blade.c 金乌刀法
#include <ansi.h>

inherit SKILL;
string *mjj = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

mapping *action = ({
([      "action" : "$N手中$w直劈，一招"+(mjj[random(13)])+"「开门揖盗」"NOR"，挟着劲风万丈之式，向$n当头而下",
        "force" : 230,
        "dodge" : -10,
        "damage" : 100,
        "damage_type" : "割伤" ]),
([      "action" : "$N一招"+(mjj[random(13)])+"「梅雪逢夏」"NOR"，卷起一片光幕，只见刀光漫天，向$n疾卷而去",
        "force" : 250,
        "dodge" : -10,
        "damage" : 150,
        "damage_type" : "割伤"
]),
([      "action" : "$N横刀直挥，一招"+(mjj[random(13)])+"「汉将当关」"NOR"，刀身疾下,拢起一阵劲飙，向$n$l劈去",
        "force" : 280,
        "dodge" : -5,
        "damage" : 200,
        "damage_type" : "割伤"
]),
([      "action" : "$N一招"+(mjj[random(13)])+"「赤日金鼓」"NOR"，$w左右连劈六刀，一阵金芒自刀上疾射而出，映的$n\n双眼紧闭，$N乘机趋步上前,挥刀力斩$n$l",
        "force" : 300,
        "dodge" : -5,
        "damage" : 220,
        "damage_type" : "割伤"
]),
([      "action" : "$N手中$w一沉，一招"+(mjj[random(13)])+"「千钧压驼」"NOR"，$w看似沉滞不堪,实则似缓实快，自下挽了一个刀花，\n直劈$n$l",
        "force" : 300,
        "dodge" : 5,
        "damage" : 250,
        "damage_type" : "割伤"
]),
([      "action" : "$N将$w往后一带，使出一招"+(mjj[random(13)])+"「大海沉沙」"NOR"，$w顿时消失得无影无踪，$n正惊疑间，\n只见刀光一闪，$w已迅如闪电般斩往$l",
        "force" : 350,
        "dodge" : 5,
        "damage" : 300,
        "damage_type" : "割伤"
]),
([      "action" : "$N一招"+(mjj[random(13)])+"「鲍鱼之肆」"NOR"，挥舞$w狂劈十八刀，看似混乱不堪，实则刀刀劈向$n要害",
        "force" : 400,
        "dodge" : 5,
        "damage" : 350,
        "damage_type" : "劈伤"
]),
([      "action" : "$N踏步上前，使出"+(mjj[random(13)])+"「赤日炎炎」"NOR"，手中$w倒提横挥，化成一簇簇烈焰，向$n劈头盖脸的斩去",
        "force" : 500,
        "dodge" : 10,
        "damage" : 500,
        "damage_type" : "刺伤"
]),
});

int valid_learn(object me)
{
    object ob;
    if( (int)me->query("max_neili") < 500 )
        return notify_fail("你的内力不够，没有办法练金乌刀法。\n"); 
        if( (int)me->query_skill("xueshan-sword",1)<80)
                return notify_fail("金乌刀法必须有雪山剑法为根底才能练习。\n");
    if( !(ob = me->query_temp("weapon"))
    ||      (string)ob->query("skill_type") != "blade" )
        return notify_fail("你必须先找一把刀才能练刀法。\n");

    return 1;
}

int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }

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
        level   = (int) me->query_skill("jinwu-blade",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if( (int)me->query("qi") < 20
        ||      (int)me->query("neili") < 10 )
                return notify_fail("你的内力或气不够，没有办法练习金乌刀法。\n");
        me->receive_damage("qi", 10);
        me->add("neili", -5);
        write("你按著所学练了一遍金乌刀法。\n");
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"jinwu-blade/" + action;
}


