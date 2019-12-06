// huashan-zhangfa.c ��ɽ�Ʒ�
inherit SKILL;
mapping *action = ({
([  "action" : "$Nһʽ��"+RED+"���Ƴ��"+NOR+"����˫�Ƽ�����һ�ŵ����İ�����������$n��$l",
    "force" : 180,
    "lvl" : 0,
    "skill_name" : RED "���Ƴ��" NOR,
        "damage_type" : "����"
]),
([  "action" : "$N��ָ�罣��һʽ��"+HIW+"�׺����"+NOR+"��������$n��$l��ȥ",
    "force" : 220,
    "lvl" : 10,
    "skill_name" : HIW "�׺����" NOR,
        "damage_type" : "����"
]),
([  "action" : "$Nʹһʽ��"+HIW+"�ƶ�����"+NOR+"��������΢��������է��է�ϣ��͵ز���$n��$l",
    "force" : 260,
    "lvl" : 20,
    "skill_name" : HIW "�ƶ�����" NOR,
        "damage_type" : "����"
]),
([  "action" : "$N˫����������������һʽ��"+GRN+"���ɴ��"+NOR+"�����ó�������̵����룬������$n��ȥ",
    "force" : 300,
    "lvl" : 30,
    "skill_name" : GRN "���ɴ��" NOR,
        "damage_type" : "����"
]),
([  "action" : "$N��������һ�ݣ�ʹ��һʽ��"+BLU+"��������"+NOR+"����˫�Ʋ�£����ֱ����$n��$l��ȥ",
    "force" : 340,
    "lvl" : 40,
    "skill_name" : BLU "��������" NOR,
        "damage_type" : "����"
]),
([  "action" : "$N����һ�䣬ʹһʽ��"+RED+"�ޱ���ľ"+NOR+"����˫�ƴ�����ɲ�ľ������͵ػ���$n��$l",
    "force" : 380,
    "lvl" : 50,
    "skill_name" : RED "�ޱ���ľ" NOR,
        "damage_type" : "����"
]),
([  "action" : "$Nʹһʽ��"+GRN+"��ɽ��ˮ"+NOR+"�����������أ�������ӯ��ͬʱ��$n��$l��ȥ",
    "force" : 420,
    "lvl" : 60,
    "skill_name" : GRN "��ɽ��ˮ" NOR,
        "damage_type" : "����"
]),
([  "action" : "$Nͻ��һ�С�"+CYN+"��������"+NOR+"����˫��Ю��һ�����֮�ƣ��͵�����$n��$l",
    "force" : 460,
    "lvl" : 70,
    "skill_name" : CYN "��������" NOR,
        "damage_type" : "����"
]),
([  "action" : "$Nһʽ��"+HIW+"�������"+NOR+"����˫�������һ����裬�����ѻ���$n��$l��",
    "force" : 500,
    "lvl" : 80,
    "skill_name" : HIW "�������" NOR,
        "damage_type" : "����"
]),
([  "action" : "$Nһʽ��"+YEL+"����Ʈ��"+NOR+"������������������˫��һ��һ�ͣ����Ƽ򵥣�ȴ��$n�޷�����",
    "force" : 540,
    "lvl" : 90,
    "skill_name" : YEL "����Ʈ��" NOR,
        "damage_type" : "����"
])
});
int valid_enable(string usage) { return usage=="unarmed" || usage=="parry"; }
int practice_level(){   return 90;  }
int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("����ɽ�Ʒ�������֡�\n");
    if ((int)me->query_skill("zixia-shengong", 1) < 20)
        return notify_fail("�����ϼ�񹦻�򲻹����޷�ѧ��ɽ�Ʒ���\n");
    if ((int)me->query("max_neili") < 120)
        return notify_fail("�������̫�����޷�����ɽ�Ʒ���\n");
    if (me->query_skill("unarmed", 1) <=me->query_skill("huashan-zhangfa", 1))
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
    int i, level;
    mapping a_action;
    level   = (int) me->query_skill("huashan-zhangfa",1);
    for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action=action[NewRandom(i, 20, level/5)];
                       break;
                 }
    a_action["dodge"]  = 0-level/2;
    a_action["parry"]  = 0-level/2;
    a_action["damage"] = level;
    return a_action;
}

int practice_skill(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("����ɽ�Ʒ�������֡�\n");
    if ((int)me->query("qi") < 30)
        return notify_fail("�������̫���ˡ�\n");
    if ((int)me->query("neili") < 40)
        return notify_fail("���������������ɽ�Ʒ���\n");
    me->receive_damage("qi", 30);
    me->add("neili", -10);
    return 1;
}
string perform_action_file(string action)
{
    return __DIR__"huashan-zhangfa/" + action;
}
