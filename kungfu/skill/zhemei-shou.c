// SKILL zhemei-shou.c
inherit SKILL;
mapping *action = ({
([  "action" : "$Nһ�С�"+HIC+"��÷��Թ"+NOR+"����˫�ֺ�ӣ�ץ��$n",
    "force" : 130,
    "lvl" : 0,
    "skill_name" : BLK "��÷��Թ" NOR,
    "damage_type" : "����"
]),
([  "action" : "$Nһ�С�"+RED+"�ƻ���Գ�"+NOR+"��������ԾȻ����ץ��$n��ͷ��",
    "force" : 150,
    "lvl" : 10,
    "skill_name" : RED "�ƻ���Գ�" NOR,
    "damage_type" : "����"
]),
([  "action" : "$Nһ�С�"+GRN+"��ɽһ�����ı�"+NOR+"����˫�ַ׷ɣ�$nֻ���ۻ�����",
    "force" : 150,
    "lvl" : 30,
    "skill_name" : GRN "��ɽһ�����ı�" NOR,
    "damage_type" : "����"
]),
([  "action" : "$Nһ�С�"+YEL+"÷��ѩ�串��ƻ"+NOR+"����˫�ֺϻ���$nֻ���޴��ɱ�",
    "force" : 150,
    "lvl" : 40,
    "skill_name" : YEL "÷��ѩ�串��ƻ" NOR,
    "damage_type" : "����"
]),
([  "action" : "$Nһ�С�"+HIC+"������÷��ѩ��"+NOR+"����˫��ƮȻץ��$n",
    "force" : 250,
    "lvl" : 50,
    "skill_name" : HIC "������÷��ѩ��" NOR,
    "damage_type" : "����"
]),
([  "action" : "$N˫��ƽ�٣�һ�С�"+HIW+"����������ŪӰ"+NOR+"������$n",
    "force" : 300,
    "lvl" : 60,
    "skill_name" : HIW "����������ŪӰ" NOR,
            "damage_type" : "����"
]),
([  "action" : "$Nһ�С�"+WHT+"��������ֱ����"+NOR+"��������$n���ƺ�$n��ȫ��������",
    "force" : 350,
    "lvl" : 70,
    "skill_name" : WHT "��������ֱ����" NOR,
    "damage_type" : "����"
]),
([  "action" : "$N������Σ�����һ�ǡ�"+MAG+"����δ�϶��Ⱦ�"+NOR+"������$n��ͷ��",
    "force" : 350,
    "lvl" : 80,
    "skill_name" : MAG "����δ�϶��Ⱦ�" NOR,
           "damage_type" : "����"
]),
([  "action" : "$Nʩ����"+RED+"����Ц��"+NOR+"�������ֺ�ɨ$n��$l�����ֹ���$n���ؿ�",
    "force" : 400,
    "lvl" : 90,
    "skill_name" : RED "����Ц��" NOR,
            "damage_type" : "����"
]),
([  "action" : "$Nʩ����"+YEL+"��ʯ���"+NOR+"��������һ������$n",
    "force" : 450,
    "lvl" : 100,
    "skill_name" : YEL "��ʯ���" NOR,
            "damage_type" : "����"
])
});
int valid_enable(string usage) { return usage=="hand" || usage=="parry"; }
int practice_level(){   return 100;  }

int valid_combine(string combo) { return combo=="liuyang-zhang"; }
int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("����ɽ��÷�ֱ�����֡�\n");
    if ((int)me->query("max_neili") < 50)
        return notify_fail("�������̫�����޷�����ɽ��÷�֡�\n");
if (me->query_skill("hand", 1) <=me->query_skill("zhemei-shou", 1))
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
    level   = (int) me->query_skill("zhemei-shou",1);
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
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("����ɽ��÷�ֱ�����֡�\n");
    if ((int)me->query("qi") < 30)
        return notify_fail("�������̫���ˡ�\n");
    if ((int)me->query("neili") < 20)
        return notify_fail("���������������ɽ��÷�֡�\n");
    me->receive_damage("qi", 25);
    me->add("neili", -10);
    return 1;
}
string perform_action_file(string action)
{
    return __DIR__"zhemei-shou/" + action;
}
