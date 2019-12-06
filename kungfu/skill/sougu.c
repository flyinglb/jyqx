//sougu.c �ѹ�ӥצ��
inherit SKILL;
mapping *action = ({
([  "action" : "$N˫��һ£����צֱ��$n���̣���צȴЮ����֮������$n���䣬һ��һʵ������һ�С�"+HIB+"��צʽ"+NOR+"��",
    "force" : 170,
    "damage_type" : "ץ��",
    "lvl" : 0,
    "skill_name" : BLU "��צʽ" NOR,
]),
([  "action" : "$N���ζ�������ӥ���հ㡰ٿ���ش�$nͷ��Խ����ʹһ�С�"+WHT+"��צʽ"+NOR+"��˫צ����$n�Ժ����",
    "force" : 190,
    "damage_type" : "ץ��",
    "lvl" : 14,
    "skill_name" : WHT "��צʽ" NOR,
]),
([  "action" : "$N�͵�һ����ͻȻ����$n��ǰ��ʹһ�С�"+RED+"��צʽ"+NOR+"������צֱ��$nС��",
    "force" : 215,
    "damage_type" : "ץ��",
    "lvl" : 35,
    "skill_name" : RED "��צʽ" NOR,
]),
([  "action" : "$N��צ���أ���צ�����󷢣�һ�С�"+MAG+"��צʽ"+NOR+"������������$n��$l",
    "force" : 245,
    "damage_type" : "ץ��",
    "lvl" : 58,
    "skill_name" : MAG "��צʽ" NOR,
]),
([  "action" : "$N���ι��죬����ǰ�ˣ�ʹһ�С�"+CYN+"��צʽ"+NOR+"����ֱ��$n�ɲ�",
    "force" : 280,
    "damage_type" : "ץ��",
    "lvl" : 70,
    "skill_name" : CYN "��צʽ" NOR,
]),
([  "action" : "$N����Ʈ������Ȼת��$n���һ�С�"+BLK+"��צʽ"+NOR+"����˫צֱ��$n�ʺ����",
    "force" : 320,
    "damage_type" : "ץ��",
    "lvl" : 81,
    "skill_name" : BLK "��צʽ" NOR,
]),
([  "action" : "$Nһ����Х�����ΰ���ʹ����"+YEL+"ǧצʽ"+NOR+"�����ɰ�������»���$n�پ�����צӰ������ȫ����Ѩ",
    "force" : 365,
    "damage_type" : "ץ��",
    "lvl" : 94,
    "skill_name" : YEL "ǧצʽ" NOR,
])
});
int valid_enable(string usage) { return usage=="unarmed" ||  usage=="parry"; }
int practice_level(){   return 100;  }
int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("���ѹ�ӥצ��������֡�\n");
    if (me->query_skill("unarmed", 1) <=me->query_skill("sougu", 1))
        return notify_fail("��Ļ����������޷���������ļ��ɡ�\n");
    if ((int)me->query("max_neili") < 100)
        return notify_fail("�������̫�����޷�ѧ�ѹ�ӥצ����\n");
    if ((int)me->query("str") < 24)
        return notify_fail("��ı���̫��޷�ѧ�ѹ�ӥצ����\n");
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
    level = (int)me->query_skill("sougu", 1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action = action[NewRandom(i, 20, level/5)];
                        break;
                }
    a_action["dodge"]  = 0-level/2;
    a_action["parry"]  = 0-level;
    a_action["attack"]  = level;
    a_action["damage"] = level*2;
    return a_action;

}
int practice_skill(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("���ѹ�ӥצ��������֡�\n");
    if ((int)me->query("qi") < 30)
        return notify_fail("�������̫���ˡ�\n");
    if ((int)me->query("neili") < 20)
        return notify_fail("�������������ӥצ����\n");
    me->receive_damage("qi", 25);
    me->add("neili", -5);
    return 1;
}
string perform_action_file(string action)
{
    return __DIR__"sougu/" + action;
}
