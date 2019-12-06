//modified by wind
// poyu-quan.c ��ʯ����ȭ
inherit SKILL;
mapping *action = ({
([  "action" : "$N�ҽ������������㣬һʽ��"+HIW+"����ʽ"+NOR+"����������һ��һ�ͣ�����$n��$l",
    "force" : 180,
    "lvl" : 0,
    "skill_name" : HIW "����ʽ" NOR,
    "damage_type" : "����"
]),
([  "action" : "$N�����̤��ȫ����ת��һ�С�"+WHT+"ʯ��"+BLU+"�쾪"+NOR+"������ȭ�͵ػ���$n��$l",
    "force" : 200,
    "lvl" : 60,
    "skill_name" : WHT "ʯ���쾪" NOR,
    "damage_type" : "����"
]),
([  "action" : "$N˫�ִ󿪴��أ����߾٣�ʹһ�С�"+HIC"+���ź���"+NOR+"����˫ȭ��$n��$l��ȥ",
    "force" : 220,
    "lvl" : 40,
    "skill_name" : HIC "���ź���" NOR,
    "damage_type" : "����"
]),
([  "action" : "$N����Ȧ���������⵱�أ����ֻ��ڳ��ϣ�һ�С�"+MAG+"ǧ��׹��"+NOR+"������$n��$l",
    "force" : 260,
    "lvl" : 20,
    "skill_name" : MAG "ǧ��׹��" NOR,
    "damage_type" : "����"
]),
([  "action" : "$Nʹһ�С�"+RED+"��������"+NOR+"��������ǰ̽��˫ȭ���˸���Ȧ������$n��$l",
    "force" : 300,
    "lvl" : 10,
    "skill_name" : RED "��������" NOR,
    "damage_type" : "����"
]),
([  "action" : "$N˫ȭ������һ�ǡ�"+YEL+"���ֿβ"+NOR+"�����Ƴ���磬һ�����е�$n������",
    "force" : 360,
    "lvl" : 20,
    "skill_name" : YEL "���ֿβ" NOR,
    "damage_type" : "����"
]),
([  "action" : "$Nʩ����"+HIM+"�����"+NOR+"����˫ȭȭ����磬ͬʱ����$nͷ���أ�������Ҫ��",
    "force" : 420,
    "lvl" : 80,
    "skill_name" : HIM "�����" NOR,
    "damage_type" : "����"
]),
([  "action" : "$N����ڿۣ�����������һʽ��"+BLK+"��ʯ��"+CYN+"��"+NOR+"����˫ȭ���봷��$n���ؿ�",
    "force" : 540,
    "lvl" : 90,
    "skill_name" : CYN "��ʯ����" NOR,
    "damage_type" : "����"
])
});
int valid_enable(string usage) { return usage=="cuff" || usage=="parry"; }
int practice_level(){   return 90;  }
int valid_combine(string combo) { return combo=="hunyuan-zhang"; }
int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("������ʯ����ȭ��������֡�\n");
    if ((int)me->query_skill("zixia-shengong", 1) < 10)
        return notify_fail("��ġ�"+MAG+"��ϼ��"+NOR+"����򲻹����޷�ѧ����ʯ����ȭ����\n");
    if ((int)me->query("max_neili") < 50)
        return notify_fail("�������̫�����޷�����"+YEL+"��ʯ����ȭ"+NOR+"����\n");
    if (me->query_skill("cuff", 1) <=me->query_skill("poyu-quan", 1))
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
    level   = (int) me->query_skill("poyu-quan", 1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action = action[NewRandom(i, 20, level/5)];
                        break;
                }
    a_action["dodge"]  = 0-level/3;
    a_action["parry"]  = 0-level/3;
    a_action["attack"]  = level/2;
    a_action["damage"] = level/3;
    return a_action;

}

int practice_skill(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("������ʯ����ȭ��������֡�\n");
    if ((int)me->query("qi") < 30)
        return notify_fail("�������̫���ˡ�\n");
    if ((int)me->query("neili") < 20)
        return notify_fail("���������������"+YEL+"��ʯ����ȭ"+NOR+"����\n");
    me->receive_damage("qi", 25);
    me->add("neili", -5);
    return 1;
}
string perform_action_file(string action)
{
    return __DIR__"poyu-quan/" + action;
}
