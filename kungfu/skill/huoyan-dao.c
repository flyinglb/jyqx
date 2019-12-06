//
// huoyan-dao.c ���浶
// Designed by secret(����)
//
inherit SKILL;
mapping *action = ({
([      "action" : "$Nʹ��һ�С�"+RED+"��ľȡ��"+NOR+"��������ת��˫����ǰƽƽ����$n",
        "skill_name" : RED "��ľȡ��" NOR,
        "force" : 100,
        "lvl" : 0,
        "damage_type" : "����",
]),
([      "action" : "$Nʹ��һ�С�"+RED+"ף�ڻ���"+NOR+"���������絶��бб����$n��$l",
        "skill_name" : RED "ף�ڻ���" NOR,
        "force" : 150,
        "lvl" : 10,
        "damage_type" : "����",
]),
([      "action" : "$Nʹ��һ�С�"+RED+"����ޱ�"+NOR+"����˫��һ�ģ�һ�����������й���$n��$l",
        "skill_name" : RED "����ޱ�" NOR,
        "force" : 200,
        "lvl" : 20,
        "damage_type" : "����",
]),
([      "action" : "$Nʹ��һ�С�"+RED+"�����ֻ�"+NOR+"����˫�ֺ�ʮ����ͷ����$n",
        "skill_name" : RED "�����ֻ�" NOR,
        "force" : 250,
        "lvl" : 30,
        "damage_type" : "����",
]),
([      "action" : "$Nʹ��һ�С�"+RED+"˫������"+NOR+"����˫��һ�������������湥��$n��$l",
        "skill_name" : RED "˫������" NOR,
        "force" : 300,
        "lvl" : 40,
        "damage_type" : "����",
]),
([      "action" : "$Nʹ��һ�С�"+RED+"��ɽ��"+NOR+"����˫������б�ģ���ʱ��ǧ������������˷�����$n",
        "skill_name" : RED "��ɽ��" NOR,
        "force" : 350,
        "lvl" : 60,
        "damage_type" : "����",
]),
([      "action" : "$Nʹ��һ�С�"+RED+"�׷���"+NOR+"������ۻ��գ�����������ֱ��$n��$l",
        "skill_name" : RED "�׷���" NOR,
        "force" : 400,
        "lvl" : 80,
        "damage_type" : "����",
]),
([      "action" : "$Nʹ��һ�С�"+RED+"��������"+NOR+"����˫��΢��������ǰ�죬һ���ھ�����ɽ�����㹥��$n",
        "skill_name" : RED "��������" NOR,
        "force" : 500,
        "lvl" : 100,
        "damage_type" : "����",
]),
});

  int valid_enable(string usage) { return usage == "unarmed" || usage == "parry"; }
int practice_level(){   return 100;  }
int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("�����浶������֡�\n");
    else if ((int)me->query("max_neili") < 1000) //  ���浶Ҫ�кܸߵ���������ѧ
        return notify_fail("�������������\n");
    if (me->query_skill("unarmed", 1) <=me->query_skill("huoyan-dao", 1))
        return notify_fail("��Ļ����������޷���������ļ��ɡ�\n");
    if ((int)me->query_skill("longxiang", 1) >= 60 ||
        (int)me->query_skill("xiaowuxiang", 1) >= 60)
        return 1;
    else if ((int)me->query_skill("longxiang", 1) < 60)
        return notify_fail("���������������̫ǳ��\n");
    else if ((int)me->query_skill("xiaowuxiang", 1) < 60)
        return notify_fail("���С���๦���̫ǳ��\n");
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
    mapping a_action;
    level   = (int) me->query_skill("huoyan-dao",1);
    for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action=action[NewRandom(i, 20, level/5)];
                       break;
                 }
    a_action["dodge"]  = 0-level;
    a_action["parry"]  = 0-level;
    a_action["damage"] = level;
    return a_action;
}

int practice_skill(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("�����浶������֡�\n");
    if ((int)me->query("qi") < 40)
        return notify_fail("������������������˻��浶��\n");
    me->receive_damage("qi", 20);
    return 1;
}

string perform_action_file(string action)
{
    return __DIR__"huoyan-dao/" + action;
}


