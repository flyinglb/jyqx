// yizhi-chan.c һָ��
inherit SKILL;
mapping *action = ({
([  "action" : "$N˫ָ��£��һʽ��"+YEL+"�������"+NOR+"����������ϣ�������һǰһ�����$n���ظ���",
    "force" : 60,
    "lvl" : 0,
    "skill_name" : YEL "�������" NOR,
    "damage_type" : "����"
]),
([  "action" : "$N���ƻ��أ�һʽ��"+RED+"�������"+NOR+"����������ָǰ���˸��뻡���͵�һ˦������$n��$l",
    "force" : 120,
    "lvl" : 20,
    "skill_name" : RED "�������" NOR,
        "damage_type" : "����"
]),
([  "action" : "$N����������һʽ��"+HIC+"���Ź��"+NOR+"����˫��ʳָ�˲������һ������������$n��ȫ��ҪѨ",
    "force" : 240,
    "lvl" : 40,
    "skill_name" : HIC "���Ź��" NOR,
        "damage_type" : "����"
]),
([  "action" : "$N��ϥ������һʽ��"+HIY+"���ޱ�"+NOR+"����������ȭ���⣬����Ĵֱָ����ңң����$nһ��",
    "force" : 480,
    "lvl" : 60,
    "skill_name" : HIY "���ޱ�" NOR,
        "damage_type" : "����"
])
});
int valid_enable(string usage) { return usage=="finger" || usage=="parry"; }
int practice_level(){   return 60;  }
int valid_combine(string combo) { return combo=="banruo-zhang"; }
int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("��һָ��������֡�\n");
    if ((int)me->query("max_neili") < 100)
        return notify_fail("�������̫�����޷���һָ����\n");
if (me->query_skill("finger", 1) <=me->query_skill("yizhi-chan", 1))
        return notify_fail("��Ļ����������޷���������ļ��ɡ�\n");
    if ((int)me->query_skill("hunyuan-yiqi", 1) < 20)
    if ((int)me->query_skill("yijing-force", 1) < 20)
    if ((int)me->query_skill("jiuyang-shengong", 1) < 20)
    if ((int)me->query_skill("taiji-shengong", 1) < 20)
        return notify_fail("�������������򲻹����޷�ѧһָ����\n");
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
    level   = (int) me->query_skill("yizhi-chan",1);
    for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action=action[NewRandom(i, 20, level/5)];
                       break;
                 }
    a_action["dodge"]  = 0-level/2;
    a_action["parry"]  = 0-level/2;
    a_action["damage"] = level/2;
    return a_action;
}

int practice_skill(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("��һָ��������֡�\n");
    if ((int)me->query("qi") < 30)
        return notify_fail("�������̫���ˡ�\n");
    if ((int)me->query("neili") < 20)
        return notify_fail("�������������һָ����\n");
    me->receive_damage("qi", 30);
    me->add("neili", -10);
    return 1;
}
string perform_action_file(string action)
{
    return __DIR__"yizhi-chan/" + action;
}
