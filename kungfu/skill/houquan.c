// houquan.c ��ȭ
inherit SKILL;
mapping *action = ({
([  "action" : "$N����΢����������ǰ�˳���һʽ��"+YEL+"�ɺ�ժ��"+NOR+"������צֱ����ץ��$n��$l",
    "force" : 180,
    "damage_type" : "ץ��",
    "lvl" : 0,
    "skill_name" : YEL "��ճ���" NOR,
]),
([  "action" : "$N������Σ�һʽ��"+MAG+"�����֦"+NOR+"��������ֱ��������$n�ļ羮��Ѩ",
    "force" : 200,
    "lvl" : 8,
    "skill_name" : MAG "�����֦" NOR,
    "damage_type" : "����"
]),
([  "action" : "$Nһ��ǰ�죬һ�ۺ�ָ��һʽ��"+RED+"Գ������"+NOR+"��������$n��$l",
    "force" : 230,
    "lvl" : 15,
    "skill_name" : RED "Գ������" NOR,
    "damage_type" : "����"
]),
([  "action" : "\n$N��Ȼ����һ�ţ�ʹһʽ��"+YEL+"�˷���Ӱ"+NOR+"����˫צ�����޶���һצץ��$n��$l",
    "force" : 230,
    "lvl" : 15,
    "skill_name" : YEL "�˷���Ӱ" NOR,
    "damage_type" : "����"
]),
([  "action" : "$N����һ������һ������ʹһʽ��"+BLU+"ˮ������"+NOR+"����˫צ������$n��$l",
    "force" : 220,
    "damage_type" : "����",
    "lvl" : 20,
    "skill_name" : BLU "ˮ������" NOR,
]),
([  "action" : "$N�͵����ϸ߸�Ծ��һʽ��"+YEL+"���ժ��"+NOR+"�����Ӹ����£�һצ����$n��ͷ��",
    "force" : 240,
    "damage_type" : "ץ��",
    "lvl" : 30,
    "skill_name" : YEL "���ժ��" NOR,
]),
});
int practice_level(){   return 30;  }
int valid_enable(string usage) { return usage=="parry"|| usage=="unarmed"; }
int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("����ȭ������֡�\n");
    if ((int)me->query_skill("force", 1) < 30)
        return notify_fail("��Ļ����ڹ���򲻹����޷�ѧ��ȭ��\n");
    if ((int)me->query("max_neili") < 200)
        return notify_fail("�������̫�����޷�����ȭ��\n");
    if (me->query_skill("unarmed", 1) <=me->query_skill("houquan", 1))
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
    level   = (int) me->query_skill("houquan",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action = action[NewRandom(i, 20, level/5)];
                        break;
                }
    a_action["dodge"]  = 0-level/3;
    a_action["parry"]  = 0-random(level/3);
    a_action["damage"] = level;
    return a_action;
}
int practice_skill(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("����ȭ������֡�\n");
    if ((int)me->query("qi") < 30)
        return notify_fail("�������̫���ˡ�\n");
    if ((int)me->query("neili") < 10)
        return notify_fail("���������������ȭ��\n");
    me->receive_damage("qi", 15);
    me->add("neili", -5);
    return 1;
}
string perform_action_file(string action)
{
    return __DIR__"houquan/" + action;
}


