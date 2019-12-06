// tianshan-zhang.c, based on dagou-bang.c
// by yucao
// Modified by Hop 97.01.05
// Added by Yzuo 97.04.08
inherit SKILL;
mapping *action = ({
([  "action": "$Nʹ��һ�С�"+CYN+"���ӿ���"+NOR+"��������$w�󿪴���ɨ��$n��$l",
    "force" : 80,
    "lvl" : 0,
    "damage_type": "����"
]),
([  "action": "$N����$w������죬һ�С�"+YEL+"ɽ������"+NOR+"����$n��$l��ȥ",
    "force" : 140,
    "lvl" : 13,
    "damage_type": "����"
]),
([  "action": "$N����$w���Ӹ�����ʹһ�С�"+HIW+"��ɽѩ��"+NOR+"������$n��$l",
    "force" : 200,
    "lvl" : 30,
    "damage_type": "����"
]),
([  "action": "$Nһ�С�"+RED+"������"+WHT+"ѩ"+NOR+"��������Ʈ�����ߣ�����$w����$n��$l",
    "force" : 240,
    "lvl" : 45,
    "damage_type": "����"
]),
([  "action": "$Nʹһ�С�"+BOLD+"�ع�õ�"+NOR+"��������$w��һ���������$n��$l",
    "force" : 270,
    "lvl" : 60,
    "damage_type": "����"
]),
([  "action": "$Nʹ���ġ�"+HIR+"��˪��Ӱ"+NOR+"����$w������Ӱ��������$n��$l",
    "force" : 300,
    "lvl" : 75,
    "damage_type": "����"
]),
([  "action": "$N��$wƾ��һָ��һ�С�"+HIB+"��ʯ����"+NOR+"������$n��$l",
    "force" : 320,
    "lvl" : 90,
    "damage_type": "����"
]),
([  "action": "$N����һԾ������$wһ�С�"+HIY+"��������"+NOR+"����׼$n��$lɨȥ",
    "force" : 340,
    "lvl" : 105,
    "damage_type": "����"
]),
([  "action": "$N����$w�й�ֱ����һʽ��"+RED+"���ȳ���"+NOR+"����׼$n��$l��ȥ",
    "force" : 350,
    "lvl" : 120,
    "damage_type": "����"
]),
([  "action": "$Nһ�С�"+MAG+"���·ת"+NOR+"����$w�����ػ���$n��$l��ȥ",
    "force" : 380,
    "lvl" :  145,
    "damage_type": "����"
]),
});
int practice_level(){   return 145;  }
mapping query_action(object me, object weapon)
{
    mapping a_action;
    int i, level;
    level   = (int) me->query_skill("tianshan-zhang", 1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action = action[NewRandom(i, 20, level/5)];
                        break;
                }
    a_action["parry"]  = 0-level*3;
    a_action["attack"]  = level/3;
    a_action["damage"] = level;
    return a_action;

}
int valid_enable(string usage) { return (usage == "staff") || (usage == "parry"); }
int valid_learn(object me)
{
    object weapon;
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "staff")
    if (!objectp(weapon = me->query_temp("secondary_weapon"))
    || (string)weapon->query("skill_type") != "staff")
        return notify_fail("��ʹ�õ��������ԡ�\n");

    if ((int)me->query("max_neili") < 80)
        return notify_fail("�������������\n");
    if (me->query_skill("staff", 1) <=me->query_skill("tianzhan-zhang", 1))
        return notify_fail("��Ļ����������޷���������ļ��ɡ�\n");
    return 1;
}
int practice_skill(object me)
{
    object weapon;
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "staff")
    if (!objectp(weapon = me->query_temp("secondary_weapon"))
    || (string)weapon->query("skill_type") != "staff")
        return notify_fail("��ʹ�õ��������ԡ�\n");
    if ((int)me->query("qi") < 50)
        return notify_fail("���������������ɽ�ȷ���\n");
    me->receive_damage("qi", 25);
    return 1;
}
