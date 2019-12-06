// luoying-shenjian.c 落英神剑
#include <ansi.h>
inherit SKILL;
mapping *action = ({
    ([  "name":         RED "落英缤纷" NOR,
        "action":       "$N使一招「"+RED+"落英缤纷"+NOR+"」，身形向上飘起，手中$w虚虚实实幻出万点剑花纷纷扬扬撒向$n$l",
        "force":        100,
    "damage_type":  "刺伤"
    ]),
    ([  "name":         RED "人面桃花" NOR,
        "action":       "$N舞动$w，一式「"+MAG+"人面桃花"+NOR+"」，左手向$n面门一晃，右手$w抖出几朵剑花挟着虎虎剑气刺向$n的$l",
        "force":        140,
        "damage_type":  "刺伤"
    ]),
    ([  "name":         MAG "急风骤雨" NOR ,
        "action":       "$N身形绕$n一转，手中$w望空一指，一式「"+MAG+"急风骤雨"+NOR+"」幻出满天剑影，向$n$l接连挥出数剑",
        "force":        180,
        "damage_type":  "割伤"
    ]),
    ([  "name":         RED "江城飞花" NOR,
        "action":       "$N身形飘然而起，在半空中身子一旋，悠然一式「"+RED+"江城飞花"+NOR+"」手中$w若有若无淡淡刺向$n的$l",
        "force":        210,
        "damage_type":  "刺伤"
    ]),
    ([  "name":         WHT "万花齐落" NOR,
        "action":       "$N纵起丈余，头下脚上，一招「"+BLU+"万花齐落"+NOR+"」手中$w舞成一个光球罩向$n的$l",
        "force":        240,
    "damage_type":  "刺伤"
    ]),
    ([  "name":         BLK "漫天花雨" NOR,
        "action":       "$N一声大喝使出「"+HIC+"漫天花雨"+NOR+"」，手中$w幻出漫天花瓣，迅若奔雷射向$n的$l",
        "force":        280,
    "damage_type":  "刺伤"
    ]),
    ([  "name":         MAG "落花无意" NOR,
        "action":       "$N轻叹一声，手中$w怀中一抱，一时「"+HIY+"落花无意"+NOR+"」，$w锵然跃出倏的化作几点带露的桃花，飘然飞向$n的$l",
        "force":        320,
    "damage_type":  "刺伤"
    ]),
});
int practice_level(){   return 110;  }
int valid_learn(object me)
{
    object ob;
    if( (int)me->query_skill("bibo-shengong",1) < 30)
        return notify_fail("你的碧波神功火候还不够。\n");
    if( (int)me->query("max_neili") < 100 )
        return notify_fail("你的内力不够，不能练落英神剑。\n");
    if (!objectp(ob = me->query_temp("weapon"))
    || (string)ob->query("skill_type") != "sword")
        return notify_fail("你必须先找一把剑才能学习剑法。\n");
    if (me->query_skill("sword", 1) <=me->query_skill("luoying-shenjian", 1))
        return notify_fail("你的基础不够，无法领会更高深的技巧。\n");
    return 1;
}
int valid_enable(string usage)
{
    return usage=="sword" || usage=="parry";
}
mapping query_action(object me, object weapon)
{
    int level=me->query_skill("luoying-shenjian",1);
    mapping a_action = action[random(sizeof(action))];
    a_action["dodge"]=0-level/3;
    a_action["attack"]=level/3;
    a_action["damage"]=level/2;
    return a_action;
}
int practice_skill(object me)
{
    object ob;
    if( (int)me->query("qi") < 30
    ||  (int)me->query("neili") < 15 )
        return notify_fail("你的内力或气不够，没有办法练习落英神剑。\n");
    if (!objectp(ob = me->query_temp("weapon"))
    || (string)ob->query("skill_type") != "sword")
    if (!objectp(ob = me->query_temp("secondary_weapon"))
    || (string)ob->query("skill_type") != "sword")
        return notify_fail("你必须先找一把剑才能习练剑法。\n");
    me->receive_damage("qi", 30);
    me->add("force", -10);
    return 1;
}
