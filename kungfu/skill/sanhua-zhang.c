// sanhua-zhang.c -ɢ����
inherit SKILL;
mapping *action = ({
([  "action" : "$N���Ʊ���һʽ��"+GRN+"����ݾ�"+NOR+"����˫�Ʊ�����£���������$n��$l",
    "force" : 180,
    "lvl" : 0,
    "skill_name" : GRN "����ݾ�" NOR,
        "damage_type" : "����"
]),
([  "action" : "$N��ָ������һʽ��"+YEL+"���ж���ܰ"+NOR+"���������ƴ��巭�ɣ�����$n��$l��ȥ",
    "force" : 260,
    "lvl" : 25,
    "skill_name" : YEL "���ж���ܰ" NOR,
        "damage_type" : "����"
]),
([  "action" : "$Nʹһʽ��"+BLU+"�ﺨ��˪��"+NOR+"�����������У�����է��է�ϣ��͵ز���$n��$l",
    "force" : 340,
    "lvl" : 56,
    "skill_name" : BLU "�ﺨ��˪��" NOR,
        "damage_type" : "����"
]),
([  "action" : "$N˫��Ѫ�죬һʽ��"+HIW+"������÷��"+NOR+"�����ó�����÷����䣬������$n��ȥ",
    "force" : 420,
    "lvl" :  72,
    "skill_name" : HIW "������÷��" NOR,
        "damage_type" : "����"
])
});
int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }
int practice_level(){   return 72;  }
int valid_combine(string combo) { return combo=="nianhua-zhi"; }

int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("��ɢ���Ʊ�����֡�\n");
    if ((int)me->query("max_neili") < 100)
        return notify_fail("�������̫�����޷���ɢ���ơ�\n");
if (me->query_skill("strike", 1) <=me->query_skill("sanhua-zhang", 1))
        return notify_fail("��Ļ����������޷���������ļ��ɡ�\n");
    if ((int)me->query_skill("hunyuan-yiqi", 1) < 20)
    if ((int)me->query_skill("yijing-force", 1) < 20)
    if ((int)me->query_skill("jiuyang-shengong", 1) < 20)
    if ((int)me->query_skill("taiji-shengong", 1) < 20)
        return notify_fail("�������������򲻹����޷�ѧɢ���ơ�\n");
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
    level   = (int) me->query_skill("sanhua-zhang", 1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action = action[NewRandom(i, 20, level/5)];
                        break;
                }
    a_action["dodge"]  = 0-level/3;
    a_action["parry"]  = 0-level/2;
    a_action["attack"]  = level/2;
    a_action["damage"] = level/3;
    return a_action;

}
int practice_skill(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("��ɢ���Ʊ�����֡�\n");
    if ((int)me->query("qi") < 30)
        return notify_fail("�������̫���ˡ�\n");
    if ((int)me->query("neili") < 20)
        return notify_fail("�������������ɢ���ơ�\n");
    me->receive_damage("qi", 30);
    me->add("neili", -10);
    return 1;
}
