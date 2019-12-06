// xunlei-sword.c Ѹ�׽�
inherit SKILL;
mapping *action = ({
([  "action":"$Nʹһʽ��"+BLK+"��������"+NOR+"��������$w���죬���캮�⣬���з���֮����������ӿ��$n��$l",
    "force" : 120,
    "lvl" : 0,
    "skill_name" : BLK "��������" NOR,
    "damage_type":  "����"
]),
([  "action":"$N����ǰ��ʹ����"+RED+"����ɻ�"+NOR+"��������$w��ʱ��â���䣬����������ѩ������$n��$l",
    "force" : 140,
    "lvl" : 20,
    "skill_name" : RED "����ɻ�" NOR,
    "damage_type":  "����"
]),
([  "action":"$N����$wһ����һ�С�"+GRN+"��Ӱ����"+NOR+"����$w������ɨ��Ҷ�㼱����$n��$l",
    "force" : 160,
    "lvl" : 34,
    "skill_name" : GRN "��Ӱ����" NOR,
    "damage_type":  "����"
]),
([  "action":"$N����$w���ॳ���һ����һʽ��"+BLU+"�����ʳ"+NOR+"����$wͷ�Ͻ����������£�����֮���������ױ���$n��$l",
    "force" : 180,
    "lvl" : 47,
    "skill_name" : BLU "�����ʳ" NOR,
    "damage_type":  "����"
]),
([  "action":"$Nһʽ��"+MAG+"���絹��"+NOR+"��������$w�����������ϣ��˵��ޱȶ���ʹ$n�Ѷ���ʵ���޿ɶ��",
    "force" : 220,
    "lvl" : 60,
    "skill_name" : MAG "���絹��" NOR,
    "damage_type":  "����"
]),
([  "action":"$N����$w,һʽ��"+BLU+"���޵���"+NOR+"�����·�һ�����εĺ�����$n��$lбб����",
    "force" : 260,
    "lvl" : 80,
    "skill_name" : BLU "���޵���" NOR,
    "damage_type":  "����"
]),
([  "action":"$Nһʽ��"+HIR+"����ʧɫ"+NOR+"����$w����������罭�ӵ�к����â�����޾���$n���ؿڵ�ȥ",
    "force" : 380,
    "lvl" : 110,
    "skill_name" : HIR "����ʧɫ" NOR,
    "damage_type":  "����"
]),
([  "action":"$Nһʽ��"+YEL+"����ɽ�"+NOR+"����$w�����һ����ȫ��������ע����֮�ϣ��������է����$n��ȥ",
    "force" : 380,
    "lvl" : 150,
    "skill_name" : HIY "����ɽ�" NOR,
    "damage_type":  "����"
])
});
int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }
int practice_level(){   return 150;  }
int valid_learn(object me)
{
    object weapon;
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "sword")
    if (!objectp(weapon = me->query_temp("secondary_weapon"))
    || (string)weapon->query("skill_type") != "sword")
        return notify_fail("�������Ū�ѽ�����ѧѸ�׽�����\n");
    if (me->query_skill("sword", 1) <= me->query_skill("xunlei-sword",1))
       return notify_fail("��Ļ����������޷���������ļ��ɡ�\n");
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
        level   = (int) me->query_skill("xunlei-sword",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action=action[NewRandom(i, 20, level/5)];
                       break;
                 }
    a_action["dodge"]  = 0-level*2;
    a_action["parry"]  = 0-level/2;
    a_action["attack"]  = level;
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
        return notify_fail("�������������Ѹ�׽���\n");
    if ((int)me->query("neili") < 50)
        return notify_fail("���������������Ѹ�׽���\n");
    me->receive_damage("qi", 25);
    me->add("neili",-20);
    return 1;
}
