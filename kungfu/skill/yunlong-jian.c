// yunlong-jian.c ������
inherit SKILL;
mapping *action = ({
([  "action":"\n$Nʹһʽ��"+YEL+"����˳��Ȼ"+NOR+"��������$w����΢�񣬻ó�һ���׹����$n��$l",
    "force" : 120,
    "lvl" : 0,
    "skill_name" : YEL "����˳��Ȼ" NOR,
    "damage_type":  "����"
]),
([  "action":"\n$N����ǰ��ʹ����"+MAG+"��ȾһƬ��"+NOR+"���������������ޣ�$w��������$n��$l��ȥ",
    "force" : 140,
    "lvl" : 8,
    "skill_name" : MAG "��ȥ������" NOR,
    "damage_type":  "����"
]),
([  "action":"\n$Nһʽ��"+WHT+"־�����Զ"+NOR+"��������Ʈ�����ߣ��˷�����������$wңҡָ��$n��$l",
    "force" : 160,
    "lvl" : 15,
    "skill_name" : WHT "־�����Զ" NOR,
    "damage_type":  "����"
]),
([  "action":"$N��������Ծ��һʽ��"+HIR+"�����γ�"+NOR+"����������ˮ��һкǧ�����$nȫ��",
    "force" : 180,
    "lvl" : 20,
    "skill_name" : HIR "�����γ�" NOR,
    "damage_type":  "����"
]),
([  "action":"$N����$w�й�ֱ����һʽ��"+BLU+"���Ǳ��ҹ"+NOR+"����������Ϣ�ض�׼$n��$l�̳�һ��",
    "force" : 220,
    "lvl" : 30,
    "skill_name" : BLU "���Ǳ��ҹ" NOR,
    "damage_type":  "����"
]),
([  "action":"$N����$wһ����һʽ��"+HIB+"����ϸ����"+NOR+"����������Ϣ�ػ���$n��$l",
    "force" : 250,
    "lvl" : 40,
    "skill_name" : HIB "����ϸ����" NOR,
    "damage_type":  "����"
]),
([  "action":"\n$N����$wбָ���죬��â���£�һʽ��"+WHT+"��ɽ��ľ��"+NOR+"������׼$n��$lбб����",
    "force" : 280,
    "lvl" : 50,
    "skill_name" : WHT "����������" NOR,
    "damage_type":  "����"
]),
([  "action":"$N��ָ�����㣬����$w�Ƴ�����ѩ����â��һʽ��"+RED+"����һ���"+NOR+"������$n��$l",
    "force" : 320,
    "lvl" : 60,
    "skill_name" : RED "����һ���" NOR,
    "damage_type":  "����"
]),
([  "action":"$N���Ƶ�����һʽ��"+HIM+"���Ļ�����"+NOR+"����$w�Ի���Ծ�����缲�������$n��$l",
    "force" : 380,
    "lvl" : 70,
    "skill_name" : HIM "���Ļ�����" NOR,
    "damage_type":  "����"
]),
([  "action":"\n$N����һ���εض���һʽ��"+HIG+"������ͬ��"+NOR+"����$w�ó������Ӱ����$n����Χס",
    "force" : 420,
    "lvl" : 80,
    "skill_name" : HIG "������ͬ��" NOR,
    "damage_type":  "����"
]),
([  "action":"$N�������Ʈ�䣬һʽ��"+GRN+"���֪����"+NOR+"��������$wƽָ����������$n����",
    "force" : 450,
    "lvl" : 90,
    "skill_name" : GRN "���֪����" NOR,
    "damage_type":  "����"
]),
([  "action" : "$N����΢����������һ�С�"+HIW+"�ߴ���ʤ��"+NOR+"�����йǽ�����쫷�����$nȫ��",
    "force" : 500,
    "lvl" : 100,
    "skill_name" : HIW "�ߴ���ʤ��" NOR,
    "damage_type":  "����"
]),
([  "action" : "$Nļ��ʹһ�С�"+MAG+"��Ҷ����ɽ"+NOR+"������ʱ�����м���Ѫ������$nȫ��",
    "force" : 500,
    "lvl" : 110,
    "skill_name" : MAG "��Ҷ����ɽ" NOR,
    "damage_type":  "����"
]),
});
int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }
int practice_level(){   return 110;  }
int valid_learn(object me)
{
    object weapon;
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "sword")
    if (!objectp(weapon = me->query_temp("secondary_weapon"))
    || (string)weapon->query("skill_type") != "sword")
        return notify_fail("��������Ұѽ�����ѧ������\n");
    if ((int)me->query("max_neili") < 200)
        return notify_fail("�������������\n");
    if ((int)me->query_skill("yunlong-xinfa", 1) < 20)
        return notify_fail("��������ķ����̫ǳ��\n");
    if ((int)me->query_skill("force", 1) < 40)
        return notify_fail("��Ļ����ڹ����̫ǳ��\n");
    if (me->query_skill("sword", 1) <=me->query_skill("yunlong-jian", 1))
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
    level   = (int) me->query_skill("yunlong-jian",1);
    for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action=action[NewRandom(i, 20, level/5)];
                       break;
                 }
    a_action["dodge"]  = 0-level/2;
    a_action["parry"]  = 0-level/3;
    a_action["attack"]  = level/2;
    a_action["damage"] = level/2;
    return a_action;
}

int practice_skill(object me)
{
    object weapon;
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "sword")
    if (!objectp(weapon = me->query_temp("secondary_weapon"))
    || (string)weapon->query("skill_type") != "sword")
        return notify_fail("��ʹ�õ��������ԡ�\n");
    if ((int)me->query("qi") < 50)
        return notify_fail("�����������������������\n");
    me->receive_damage("qi", 25);
    return 1;
}
string perform_action_file(string action)
{
    return __DIR__"yunlong-jian/" + action;
}
