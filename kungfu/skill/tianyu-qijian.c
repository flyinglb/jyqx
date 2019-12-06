// tianyu-qijian.c �����潣
inherit SKILL;
mapping *action = ({
([  "action":"$Nʹһʽ��"+HIC+"����һ��"+NOR+"��������$w����΢�񣬻ó�һ���������$n��$l",
    "force" : 180,
    "lvl" : 0,
    "skill_name" : BLK "����һ��" NOR,
    "damage_type":  "����"
]),
([  "action":"$N����ǰ��ʹ����"+RED+"���羪��"+NOR+"��������$w����һ����������$n��$l",
    "force" : 210,
    "lvl" : 9,
    "skill_name" : RED "���羪��" NOR,
    "damage_type":  "����"
]),
([  "action":"$N����$wһ����һ�С�"+GRN+"���ھ���"+NOR+"����ббһ�������ó�������$n��$l",
    "force" : 240,
    "lvl" : 18,
    "skill_name" : GRN "���ھ���" NOR,
    "damage_type":  "����"
]),
([  "action":"$N���н����ॳ���һ����һʽ��"+BLU+"�������"+NOR+"����һ���������$n��$l",
    "force" : 270,
    "lvl" : 27,
    "skill_name" : BLU "�������" NOR,
    "damage_type":  "����"
]),
([  "action":"$Nһʽ��"+MAG+"ŭ����"+NOR+"��������$w�������������ʹ$n�Ѷ���ʵ���޿ɶ��",
    "force" : 330,
    "lvl" : 36,
    "skill_name" : MAG "ŭ����" NOR,
    "damage_type":  "����"
]),
([  "action":"$N����$wбָ���죬��â���£�һʽ��"+BLU+"�Ż�����"+NOR+"������׼$n��$lбб����",
    "force" : 390,
    "lvl" : 44,
    "skill_name" : BLU "�Ż�����" NOR,
    "damage_type":  "����"
]),
([  "action":"$Nһʽ��"+WHT+"�����ѩ"+NOR+"�������󼱶�������������⣬����$n��$l",
    "force" : 480,
    "lvl" : 52,
    "skill_name" : WHT "�����ѩ" NOR,
    "damage_type":  "����"
]),
([  "action":"$Nһʽ��"+HIR+"��ӵ�к"+NOR+"����$w��ն�������缲�������$n���ؿ�",
    "force" : 520,
    "lvl" : 60,
    "skill_name" : HIR "��ӵ�к" NOR,
    "damage_type":  "����"
]),
([  "action":"$Nһʽ��"+HIY+"�������"+NOR+"����$wͻȻ���������һƬ���Χ��$nȫ��",
    "force" : 520,
    "lvl" : 60,
    "skill_name" : HIY "�������" NOR,
    "damage_type":  "����"
])
});
int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }
int practice_level(){   return 120;  }
int valid_learn(object me)
{
    object weapon;
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "sword")
    if (!objectp(weapon = me->query_temp("secondary_weapon"))
    || (string)weapon->query("skill_type") != "sword")
        return notify_fail("�㻹�����Ұѽ����ɡ�\n");

    if (me->query_skill("sword", 1)<=me->query_skill("tianyu-qijian",1))
        return notify_fail("��Ļ����������޷���������ļ��ɡ�\n");
       if ((int)me->query_skill("bahuang-gong", 1) < 40)
        return notify_fail("��İ˻��񹦻��̫ǳ��\n");

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
    mapping a_action;
    int i, level;
    level   = (int) me->query_skill("tianyu-qijian", 1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action = action[NewRandom(i, 20, level/5)];
                        break;
                }
    a_action["dodge"]  = 0-level*3;
    a_action["attack"]  = level/2;
    a_action["damage"] = level;
    return a_action;

}

int practice_skill(object me)
{
    object weapon;
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "sword")
    if (!objectp(weapon = me->query_temp("secondary_weapon"))
    || (string)weapon->query("skill_type") != "sword")
        return notify_fail("��ʹ�õ��������ԡ�\n");
    if ((int)me->query("qi") < 50)
        return notify_fail("������������������潣��\n");
    me->receive_damage("qi", 25);
    return 1;
}
string perform_action_file(string action)
{
    return __DIR__"tianyu-qijian/" + action;
}
