// hujia-dao.c 胡家刀法
// 
#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action" : "$N手中$w一横，叫$n以为是礼敬之意，谁知这招“"+HIY+"飞狐亮刀"+NOR+"”却已攻向$n的$l。",
        "force" : 100,
        "dodge" : 30,
        "parry" : -15,
        "damage" : 20,
        "lvl" : 0,
        "skill_name" : "飞狐亮刀",
        "damage_type" : "割伤"
]),
([      "action" : "$N接着一招“"+HIM+"上步抢刀"+NOR+"”，不等对方反击，手中$w从侧面斩向$n的$l。",
        "force" : 150,
        "dodge" : 10,
        "damage" : 30,
        "lvl" : 10,
        "skill_name" : "上步抢刀",
        "damage_type" : "割伤"
]),
([      "action": "$N一招“"+HIW+"关平献印"+NOR+"”居然以刀剑势，手中$w由下而上刺向$n的胸部",
        "force" : 160,
        "dodge" : 5,
        "parry" : -10,
        "damage" : 15,
        "lvl" : 20,
        "skill_name" : "关平献印",
        "damage_type": "挫伤"
]),
([      "action": "$N身形向上起，一招“"+HIB+"飞天摘星"+NOR+"”，手中$w却从左下砍向$n的右肩。",
        "force" : 200,
        "dodge" : -20,
        "damage" : 50,
        "lvl" : 50,
        "skill_name" : "飞天摘星",
        "damage_type": "挫伤"
]),
([      "action" : "$N俯身一展“"+HIG+"鹞子翻身"+NOR+"”，一个筋斗翻出千哩，手中$w以不可思义的方向劈向$n的$l。",
        "force" : 180,
        "dodge" : 40,
        "parry" : 20,
        "damage" : 75,
        "lvl" : 80,
        "skill_name" : "鹞子翻身",
        "damage_type" : "割伤"
]),
([      "action" : "$N视对方攻击于不顾，一招“"+HIW+"怀中抱月"+NOR+"”，手中$w竟后发先至直砍向$n的$l。",
        "force" : 210,
        "dodge" : 20,
        "damage" : 120,
        "lvl" : 100,
        "skill_name" : "怀中抱月",
        "damage_type": "挫伤"
]),
([      "action" : "$n狂风暴雨的攻势被$N一招“"+HIR+"闭门铁扇"+NOR+"”封在门外，反被$N手中$w插向了$l。",
        "force" : 250,
        "dodge" : -20,
        "parry" : 20,
        "damage" : 130,
        "lvl" : 150,
        "skill_name" : "闭门铁扇",
        "damage_type": "挫伤"
]),
([      "name":         HIY"观音坐莲"NOR,
        "action":       "$N使出" +HIY"“观音坐莲”" + HIB"$n只见眼前一刀化二刀，二刀化四刀，四刀化八刀，……\n"NOR
+ "        "+RED"无数凌厉的刀光中仿佛$N化身成为千手观音，面露慈祥的微笑，\n"NOR +
BLINK HIM"             眼光忽向$n的$l，同时无限的光华掠至$l。"NOR,
        "force" : 300,
        "dodge" : 80,
        "damage" : 250,
        "parry" : 80,
        "lvl" : 200,
        "skill_name" : "观音坐莲",
        "damage_type" : "割伤"
]),
});


int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }

// int valid_combine(string combo) { return combo=="wuka-quan"; }

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 50)
                return notify_fail("你的内力不够。\n");
        if ((int)me->query_skill("force", 120) < 10)
                return notify_fail("你的内功火候太浅。\n");
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
        level   = (int) me->query_skill("hujia-dao",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        object weapon;

        if (!me->query_skill("force", 120) )
                return notify_fail("你的内功火候太浅。\n");

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "blade")
                return notify_fail("你使用的武器不对。\n");

        if ((int)me->query("qi") < 50)
                return notify_fail("你的体力不够练「胡家刀法」。\n");

        me->receive_damage("qi", 25);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"hujia-dao/" + action;
}

