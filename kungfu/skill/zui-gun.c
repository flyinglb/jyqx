// zui-gun.c -�������
inherit SKILL;
mapping *action = ({
([  "action":"��"+MAG+"���ɺ�"+CYN+"������Ȱ��������"+NOR+"����$N����$w���ᣬ��������$n��$l",
    "force" : 180,
    "lvl" : 0,
    "skill_name" : MAG " ���ɺͣ�����Ȱ��������" NOR,
    "damage_type":"����"
]),
([  "action":"��"+HIC+"���ɹã������������ɲ�"+NOR+"����$N���ƻ��أ��ұ�Ю���͵�ɨ��$n������",
    "force" : 200,
    "lvl" : 20,
    "skill_name" : HIC "���ɹã������������ɲ�" NOR ,
    "damage_type":"����"
]),
([  "action":"��"+WHT+" �ܹ��ˣ�ǧ����������"+NOR+" ����$N����$w��ָ���أ���$n��$l��ȥ",
    "force" : 230,
    "lvl" : 30,
    "skill_name" : WHT "�ܹ��ˣ�ǧ����������" NOR,
    "damage_type":"����"
]),
([  "action":"��"+RED+"�����ӣ��������������"+NOR+"����$N����$w�����˻��˸���Ȧ������$n��$l",
    "force" : 270,
    "lvl" : 40,
    "skill_name" : RED "�����ӣ��������������" NOR,
    "damage_type":"����"
]),
([  "action":" ��"+YEL+"�����룬��������������"+NOR+"����$N���й������ţ�����������$n",
    "force" : 320,
    "lvl" : 50,
    "skill_name" : YEL "�����룬��������������" NOR,
    "damage_type":"����"
]),
([  "action":"��"+HIW+"������ߵ���ɽ�����"+NOR+"����$N����֧�أ�һ��һ���������$n��$l",
    "force" : 380,
    "lvl" : 55,
    "skill_name" : HIW "������ߵ���ɽ�����" NOR,
    "damage_type":"����"
]),
([  "action":"��"+HIR+"�Ź��ϣ�����ױ�����¿"+NOR+"����$NŤ������$w�ӿ�����������$n���ؿ�",
    "force" : 450,
    "lvl" : 60,
    "skill_name" : HIR "�Ź��ϣ�����ױ�����¿" NOR,
    "damage_type":"����"
]),
([  "action":"��"+BLU+"�����������������ǧ��"+NOR+"����$N�ڿն�����ɽ��Ӱ������ѹ��$n",
    "force" : 530,
    "lvl" : 64,
    "skill_name" : BLU "�����������������ǧ��" NOR,
    "damage_type":"����"
]),
});
int valid_enable(string usage) { return (usage == "club") || (usage == "parry"); }
int practice_level(){   return 64;  }
int valid_learn(object me)
{
    object weapon;
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "club")
        return notify_fail("��ʹ�õ��������ԡ�\n");
    if ((int)me->query("max_neili") < 100)
        return notify_fail("�������������\n");
    if ((int)me->query_skill("hunyuan-yiqi", 1) < 20)
        return notify_fail("��Ļ�Ԫһ�������̫ǳ��\n");
    if (me->query_skill("club", 1) <=me->query_skill("zui-gun", 1))
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
    level   = (int) me->query_skill("zui-gun",1);
    for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action=action[NewRandom(i, 20, level/5)];
                       break;
                 }
    a_action["dodge"]  = 0-level;
    a_action["attack"]  = level/2;
    a_action["damage"] = level;
    return a_action;
}
int practice_skill(object me)
{
    object weapon;
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "club")
        return notify_fail("��ʹ�õ��������ԡ�\n");
    if ((int)me->query("qi") < 50)
        return notify_fail("����������������������\n");
    me->receive_damage("qi", 25);
    return 1;
}
string perform_action_file(string action)
{
    return __DIR__"zui-gun/" + action;
}

