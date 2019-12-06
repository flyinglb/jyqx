// SKILL liuyang-zhang.c
inherit SKILL;
mapping *action = ({
([  "action" : "$Nһ�С�"+YEL+"�����۽�"+NOR+"�������Ƶ�������֮�ϣ�����$n",
    "force" : 130,
    "lvl" : 0,
    "skill_name" : YEL "�����۽�" NOR,
    "damage_type" : "����"
]),
([  "action" : "$Nһ�С�"+RED+"�����ƶ���"+NOR+"������ɫ���أ�˫����ƮƮ������$n",
    "force" : 150,
    "lvl" : 20,
    "skill_name" : RED "�����ƶ���" NOR,
    "damage_type" : "����"
]),
([  "action" : "$Nһ�С�"+MAG+"��б��·��ϼ��"+NOR+"����˫�ƻû�һƬ��Ӱ����$n�������ڡ�",
    "force" : 150,
    "lvl" : 30,
    "skill_name" : MAG "��б��·��ϼ��" NOR,
    "damage_type" : "����"
]),
([  "action" : "$Nһ�С�"+HIC+"��������"+NOR+"������$n��$l��������",
    "force" : 200,
    "lvl" : 40,
    "skill_name" : HIC "��������" NOR,
    "damage_type" : "����"
]),
([  "action" : "$Nһ�С�"+WHT+"����һ���ͽ���"+NOR+"����ֻ��һƬ��Ӱ����$n",
    "force" : 250,
    "lvl" : 40,
    "skill_name" : WHT "����һ���ͽ���" NOR,
    "damage_type" : "����"
]),
([  "action" : "$N˫��ƽ�ӣ�һ�С�"+HIW+"��ϼ������"+NOR+"������$n",
    "force" : 300,
    "lvl" : 60,
    "skill_name" : HIW "��ϼ������" NOR,
            "damage_type" : "����"
]),
([  "action" : "$Nһ�С�"+HIR+"���ղγ���"+NOR+"����ֻ��һƬ��Ӱ����$n",
    "force" : 350,
    "lvl" : 70,
    "skill_name" : HIR "���ղγ���" NOR,
    "damage_type" : "����"
]),
([  "action" : "$N������Σ�����һ�ǡ�"+RED+"��ϼ��Ѧ�"+NOR+"������$n��ͷ��",
    "force" : 350,
    "lvl" : 80,
    "skill_name" : RED "��ϼ��Ѧ�" NOR,
           "damage_type" : "����"
]),
([  "action" : "$Nʩ����"+HIC+"��"+YEL+"�������"+NOR+"�������ֺ�ɨ$n��$l�����ֹ���$n���ؿ�",
    "force" : 400,
    "lvl" : 90,
    "skill_name" : HIC "���������" NOR,
            "damage_type" : "����"
]),
([  "action" : "$Nʩ����"+YEL+"�������"+NOR+"����˫��ͬʱ����$n��$l",
    "force" : 450,
    "lvl" : 100,
    "skill_name" : YEL "�������" NOR,
    "damage_type" : "����"
])
});
int valid_enable(string usage) { return usage=="strike" || usage=="parry" ; }
int practice_level(){   return 120;  }
int valid_combine(string combo) { return combo=="zhemei-shou"; }
int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("����ɽ�����Ʊ�����֡�\n");
    if ((int)me->query("max_neili") < 100)
        return notify_fail("�������̫�����޷��������ơ�\n");
    if (me->query_skill("strike", 1) <=me->query_skill("liuyang-zhang", 1)
    && me->query_skill("parry", 1) <=me->query_skill("liuyang-zhang", 1))
        return notify_fail("��Ļ����������޷���������ļ��ɡ�\n");
    return 1;
}

mapping query_action(object me, object weapon)
{
    mapping a_action;
    int i, level;
    level = (int) me->query_skill("liuyang-zhang",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action = action[NewRandom(i, 20, level/5)];
                        break;
                }
    a_action["dodge"]  = 0-level/3;
    a_action["damage"] = level;
    return a_action;

}
int practice_skill(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("����ɽ�����Ʊ�����֡�\n");
    if ((int)me->query("qi") < 30)
        return notify_fail("�������̫���ˡ�\n");
    if ((int)me->query("neili") < 20)
        return notify_fail("���������������ɽ�����ơ�\n");
    me->receive_damage("qi", 25);
    me->add("neili", -10);
    return 1;
}
string perform_action_file(string action)
{
    return __DIR__"liuyang-zhang/" + action;
}
