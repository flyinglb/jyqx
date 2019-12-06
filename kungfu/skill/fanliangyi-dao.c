// fanliangyi-dao.c �����ǵ���
inherit SKILL;
mapping *action = ({
([  "action" : "$N����$wбָ��һ�С�"+RED+"����һ��"+NOR+"��������һ�٣�һ����$n��$l��ȥ",
    "force" : 120,
    "lvl" : 0,
    "skill_name" : RED "����һ��" NOR,
    "damage_type" : "����"
]),
([  "action" : "$Nһ�С�"+YEL+"̫������"+NOR+"������������㣬$wһ��һ�գ�ƽ�л���$n�ľ���",
    "force" : 140,
    "lvl" : 20,
    "skill_name" : YEL "̫������" NOR,
    "damage_type" : "����"
]),
([  "action" : "$Nչ���鲽������Ծ�䣬һ�С�"+BLU+"���Ǻϵ�"+NOR+"�������滯������ն��$n",
    "force" : 160,
    "lvl" : 40,
    "skill_name" : BLU "���Ǻϵ�" NOR,
    "damage_type" : "����"
]),
([  "action" : "$Nһ�С�"+MAG+"���»���"+NOR+"����$w�󿪴��أ����϶��»���һ���󻡣���ֱ����$n",
    "force" : 180,
    "lvl" : 60,
    "skill_name" : MAG "���»���" NOR,
    "damage_type" : "����"
]),
([  "action" : "$N����$wһ����һ�С�"+GRN+"��ɫ����"+NOR+"����˫�ֳ����������У�����$n���ؿ�",
    "force" : 200,
    "lvl" : 80,
    "skill_name" : GRN "��ɫ����" NOR,
    "damage_type" : "����"
]),
([  "action" : "$N����$w��ʹ��һ�С�"+RED+"��ٲ���"+NOR+"�����������ã����ҿ�����������$n",
    "force" : 250,
    "lvl" : 100,
    "skill_name" : RED "��ٲ���" NOR,
    "damage_type" : "����"
])
});

int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }
int valid_learn(object me)
{
    object weapon;
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "blade")
    if (!objectp(weapon = me->query_temp("secondary_weapon"))
    || (string)weapon->query("skill_type") != "blade")
        return notify_fail("�����Ҫ�Ұѵ�����ѧ�����ǵ�����\n");

    if ((int)me->query("max_neili") < 100)
        return notify_fail("�������������\n");
    if ((int)me->query_skill("zixia-shengong", 1) < 10)
        return notify_fail("��ġ���ϼ�񹦡����̫ǳ��\n");
    if (me->query_skill("blade", 1) <=me->query_skill("fanliangyi-dao", 1))
        return notify_fail("��Ļ����������޷���������ļ��ɡ�\n");
    else
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
    level   = (int) me->query_skill("fanliangyi-dao",1);
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
    object weapon;
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "blade")
    if (!objectp(weapon = me->query_temp("secondary_weapon"))
    || (string)weapon->query("skill_type") != "blade")
        return notify_fail("��ʹ�õ��������ԡ�\n");
    if ((int)me->query("qi") < 50)
        return notify_fail("��������������������ǵ�������\n");
    me->receive_damage("qi", 25);
    return 1;
}
string perform_action_file(string action)
{
    return __DIR__"fanliangyi-dao/" + action;
}
