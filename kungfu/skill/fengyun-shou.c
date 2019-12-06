// fengyun-shou.c -������
inherit SKILL;
mapping *action = ({
([  "action" : "$Nһʽ��"+RED+"��������"+NOR+"�������ƻ�צ����ָ�繳��ֱ��$n������ҪѨ",
    "force" : 120,
        "lvl" : 0,
        "skill_name" : RED "��������" NOR,
    "damage_type" : "����"
]),
([  "action" : "$N������Σ�һʽ��"+RED+"�һ�����"+NOR+"������������ֱ��������$n�ļ羮��Ѩ",
    "force" : 130,
        "lvl" : 8,
        "skill_name" : RED "�һ�����" NOR,
        "damage_type" : "����"
]),
([  "action" : "$Nʹһʽ��"+HIG+"��������"+NOR+"������ָ��������ò�ʩ������$n����·Ҫ��",
    "force" : 150,
        "lvl" : 16,
        "skill_name" : HIG "��������" NOR,
        "damage_type" : "����"
]),
([  "action" : "$N����ӥץ�������߾٣�һʽ��"+YEL+"��Ŀ�ѻ�"+NOR+"������$n���нڴ���",
    "force" : 180,
        "lvl" : 24,
        "skill_name" : YEL "��Ŀ�ѻ�" NOR,
        "damage_type" : "����"
]),
([  "action" : "$Nʹһʽ��"+HIW+"�����ķ�"+NOR+"��������˷�����������Ӱ��һצͻ����ץ��$n���ؿ�",
    "force" : 220,
        "lvl" : 40,
        "skill_name" : HIW "�����ķ�" NOR,
        "damage_type" : "����"
]),
([  "action" : "$N���ֻ��ۣ�ȫ��ؽ�žž���죬һʽ��"+BLU+"ˮ������"+NOR+"��������$n��$l",
    "force" : 270,
        "lvl" : 48,
        "skill_name" : BLU "ˮ������" NOR,
        "damage_type" : "����"
]),
([  "action" : "$Nһʽ��"+HIG+"ɽ������"+NOR+"����ʮָ���죬������հ������$n��ȫ��ҪѨ",
    "force" : 330,
        "lvl" : 54,
        "skill_name" : HIG "ɽ������" NOR,
        "damage_type" : "����"
]),
([  "action" : "$N�������ţ�һʽ��"+YEL+"�������"+NOR+"������һ�������У�˫��ͬʱ����$n���ߵ���Ѩ",
    "force" : 400,
        "lvl" : 60,
        "skill_name" : YEL "�������" NOR,
        "damage_type" : "����"
])
});
int valid_enable(string usage) { return usage=="hand" || usage=="parry"; }
int practice_level(){   return 60;  }
int valid_combine(string combo) { return combo=="yingzhua-gong"; }
int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("�������ֱ�����֡�\n");
    if ((int)me->query_skill("hunyuan-yiqi", 1) < 20)
    if ((int)me->query_skill("yijing-force", 1) < 20)
    if ((int)me->query_skill("jiuyang-shengong", 1) < 20)
    if ((int)me->query_skill("taiji-shengong", 1) < 20)
        return notify_fail("�������������򲻹����޷�ѧ�����֡�\n");

    if ((int)me->query("max_neili") < 100)
        return notify_fail("�������̫�����޷��������֡�\n");
if (me->query_skill("hand", 1) <=me->query_skill("fengyun-shou", 1))
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
    level   = (int) me->query_skill("fengyun-shou",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action = action[NewRandom(i, 20, level/5)];
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
        return notify_fail("�������ֱ�����֡�\n");
    if ((int)me->query("qi") < 30)
        return notify_fail("�������̫���ˡ�\n");
    if ((int)me->query("neili") < 20)
        return notify_fail("������������������֡�\n");
    me->receive_damage("qi", 25);
    me->add("neili", -5);
    return 1;
}
