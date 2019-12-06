// mei 4/5/96
inherit SKILL;
mapping *action = ({
([      "action":"$N立定当地，时快时缓的将手中的$w在面前移动，突然一招「"+BLU+"樵夫问道"+NOR+"」向$n劈去",
        "force" : 80,
        "lvl" : 0,
        "skill_name" : "樵夫问道",
        "damage_type":  "劈伤"
]),
([      "action":"$N渊停岳峙般的身形猛的升起五丈，一招「"+RED+"飞虹惊落"+NOR+"」寒光乍现般向$n劈去",
        "force" : 90,
        "lvl" : 10,
        "skill_name" : "飞虹惊落",
        "damage_type":  "劈伤"
]),
([      "action":"$N突然暴喝一声，手里的$w一挫，一招「"+HIW+"风雪故人来"+NOR+"」劈向$n",
        "force" : 80,
        "lvl" : 25,
        "skill_name" : "风雪故人来",
        "damage_type":  "劈伤"
]),
([      "action":"$N斜移两步，手中$w发出阵阵寒光，一招「"+MAG+"似幻似真"+NOR+"」劈向$n",
        "force" : 80,
        "lvl" : 45,
        "skill_name" : "似幻似真",
        "damage_type":  "劈伤"
]),
([      "action":"$N双手一顿，一招「"+YEL+"流星雨"+NOR+"」,手中的$w以极快的速度劈向$n",
        "force" : 90,
        "lvl" : 60,
        "skill_name" : "流星雨",
        "damage_type":  "劈伤"
]),
([      "action":"$N将$w舞得尤如万条金龙，使人不敢靠近，猛的一招「"+RED+"大屠魂"+NOR+"」向$n劈去",
        "force" : 140,
        "lvl" : 80,
        "skill_name" : "大屠魂",
        "damage_type":  "劈伤"
]),
([      "action":"$N手中的$w“铛”的一声，斧锋侧翻，光铧骤闪，一招「"+HIW+"绝一闪"+NOR+"」劈向$n",
        "force" : 80,
        "lvl" : 90,
        "skill_name" : "绝一闪",
        "damage_type":  "劈伤"
]),
([      "action":"$N斧尖指天，斧锋骤颤，一招「"+RED+"天泣血"+NOR+"」数十道冷光劈向$n",
        "force" : 140,
        "lvl" : 120,
        "skill_name" : "天泣血",
        "damage_type":  "劈伤"
]),
([      "action":"$N突然一招「"+HIC+"刃无还"+NOR+"」,手中的$w像是一道穹苍中的一道闪电，劈向$n",
        "force" : 60,
        "lvl" : 150,
        "skill_name" : "刃无还",
        "damage_type":  "劈伤"
]),
([      "action":"$N一越拔空，长啸仿如龙吟，一招「"+YEL+"天外归星"+NOR+"」$w犹如一个光球，劈向$n",
        "force" : 200,
        "lvl" : 205,
        "skill_name" : "天外归星",
        "damage_type":  "劈伤"
]),
([      "action":"$N忽然步法一变，以不可言喻的快速围绕着$n，猛的一招「"+RED+"千魂入窍"+NOR+"」劈向$n",
        "force" : 340,
        "lvl" : 300,
        "skill_name" : "千魂入窍",
        "damage_type":  "劈伤"
]),
});

int valid_enable(string usage) 
{ 
    return (usage == "axe" || usage == "parry"); 
}
int practice_level(){   return 200;  }
string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}
int valid_learn(object me)
{
    return notify_fail("雷霆斧法只能通过研读(study)而获得提高。\n");
}

mapping query_action(object me, object weapon)
{
    mapping a_action;
    int i, level   = (int) me->query_skill("leiting-axe",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action = action[NewRandom(i, 20, level/5)];
                        break;
                }
    a_action["dodge"]  = 0-level;
    a_action["parry"]  = 0-level;
    a_action["attack"]  = 2*level;
    a_action["damage"] = 2*level;
    return a_action;

}

string perform_action_file(string action)
{
    return __DIR__"leiting-axe/" + action;
}

int practice_skill(object me)
{
    object weapon;
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "axe")
    if (!objectp(weapon = me->query_temp("secondary_weapon"))
    || (string)weapon->query("skill_type") != "axe")
        return notify_fail("你使用的武器不对。\n");
    if ((int)me->query("qi") < 50)
        return notify_fail("你的体力不够练雷霆斧法。\n");
    me->receive_damage("qi", 25);
    return 1;
}

