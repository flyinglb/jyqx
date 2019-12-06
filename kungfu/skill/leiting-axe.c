// mei 4/5/96
inherit SKILL;
mapping *action = ({
([      "action":"$N�������أ�ʱ��ʱ���Ľ����е�$w����ǰ�ƶ���ͻȻһ�С�"+BLU+"�Է��ʵ�"+NOR+"����$n��ȥ",
        "force" : 80,
        "lvl" : 0,
        "skill_name" : "�Է��ʵ�",
        "damage_type":  "����"
]),
([      "action":"$NԨͣ���Ű�������͵��������ɣ�һ�С�"+RED+"�ɺ羪��"+NOR+"������է�ְ���$n��ȥ",
        "force" : 90,
        "lvl" : 10,
        "skill_name" : "�ɺ羪��",
        "damage_type":  "����"
]),
([      "action":"$NͻȻ����һ���������$wһ�죬һ�С�"+HIW+"��ѩ������"+NOR+"������$n",
        "force" : 80,
        "lvl" : 25,
        "skill_name" : "��ѩ������",
        "damage_type":  "����"
]),
([      "action":"$Nб������������$w�������󺮹⣬һ�С�"+MAG+"�ƻ�����"+NOR+"������$n",
        "force" : 80,
        "lvl" : 45,
        "skill_name" : "�ƻ�����",
        "damage_type":  "����"
]),
([      "action":"$N˫��һ�٣�һ�С�"+YEL+"������"+NOR+"��,���е�$w�Լ�����ٶ�����$n",
        "force" : 90,
        "lvl" : 60,
        "skill_name" : "������",
        "damage_type":  "����"
]),
([      "action":"$N��$w�����������������ʹ�˲��ҿ������͵�һ�С�"+RED+"������"+NOR+"����$n��ȥ",
        "force" : 140,
        "lvl" : 80,
        "skill_name" : "������",
        "damage_type":  "����"
]),
([      "action":"$N���е�$w��������һ��������෭������������һ�С�"+HIW+"��һ��"+NOR+"������$n",
        "force" : 80,
        "lvl" : 90,
        "skill_name" : "��һ��",
        "damage_type":  "����"
]),
([      "action":"$N����ָ�죬���������һ�С�"+RED+"����Ѫ"+NOR+"����ʮ���������$n",
        "force" : 140,
        "lvl" : 120,
        "skill_name" : "����Ѫ",
        "damage_type":  "����"
]),
([      "action":"$NͻȻһ�С�"+HIC+"���޻�"+NOR+"��,���е�$w����һ�����е�һ�����磬����$n",
        "force" : 60,
        "lvl" : 150,
        "skill_name" : "���޻�",
        "damage_type":  "����"
]),
([      "action":"$NһԽ�οգ���Х����������һ�С�"+YEL+"�������"+NOR+"��$w����һ����������$n",
        "force" : 200,
        "lvl" : 205,
        "skill_name" : "�������",
        "damage_type":  "����"
]),
([      "action":"$N��Ȼ����һ�䣬�Բ��������Ŀ���Χ����$n���͵�һ�С�"+RED+"ǧ������"+NOR+"������$n",
        "force" : 340,
        "lvl" : 300,
        "skill_name" : "ǧ������",
        "damage_type":  "����"
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
    return notify_fail("��������ֻ��ͨ���ж�(study)�������ߡ�\n");
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
        return notify_fail("��ʹ�õ��������ԡ�\n");
    if ((int)me->query("qi") < 50)
        return notify_fail("�����������������������\n");
    me->receive_damage("qi", 25);
    return 1;
}

