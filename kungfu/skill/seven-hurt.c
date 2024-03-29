// seven-hurt.c

inherit SKILL;

mapping *action = ({
        ([      "action":               
"$N气凝丹田，右手握掌成拳缓缓推向$n的$l",
                "dodge":                20,
                "parry":                15,
                "force":                250,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N双拳一振，一股力道排山倒海般向$n的$l推了过去",
                "dodge":                10,
                "parry":                 20,
                "force":                350,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N大吼一声，一拳平平地击向$n的$l",
                "dodge":                30,
                "parry":                10,
                "force":                150,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N左手护胸，右拳直直地击向$n的$l",
                "dodge":                10,
                "parry":                30,
                "force":                260,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N双脚站个弓箭步，吐气开声，呼地一拳劈向$n$l",
                "dodge":                20,
                "parry":                30,
                "force":                400,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N左手在$n面前晃了一个虚招，右拳突然击向$n的$l",
                "dodge":                40,
                "parry":                10,
                "force":                200,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N猛吸一口气，双拳并力推出",
                "parry":                40,
                "force":                320,
                "damage_type":  "瘀伤"
        ]),
});

int valid_learn(object me)
{
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
                return notify_fail("练七伤拳必须空手。\n");
        if( (int)me->query_skill("sunforce", 1) < 20 )
                return 
notify_fail("你的九阳神功火候不足，无法练七伤拳。\n");
        if( (int)me->query("max_force") < 150 )
                return notify_fail("你的内力太弱，无法练七伤拳法。\n");
        return 1;
}

int valid_enable(string usage) { return usage=="unarmed" || usage=="parry"; }

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30 )
                return notify_fail("你的体力不够了，休息一下再练吧。\n");
        if( (int)me->query("force") < 5 )
                return notify_fail("你的内力不够了，休息一下再练吧。\n");
        me->receive_damage("kee", 30);
        me->add("force", -5);
        return 1;
}

int enable_factor() { return 18; }

int learn_bonus() { return 12; }

int practice_bonus() { return 13; }

int study_bonus() { return 15; }