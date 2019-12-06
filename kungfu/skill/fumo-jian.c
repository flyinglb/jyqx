// fumo-jian.c -��ħ��
inherit SKILL;
mapping *action = ({
([  "action" : "$Nһʽ��"+HIW+"������"+NOR+"��������ƽָ��������磬һ���ǳɺ�ɨ$n������",
    "force" : 120,
    "lvl" : 0,
    "skill_name" : HIW "������" NOR,
    "damage_type" : "����"
]),
([  "action" : "$N��ǰԾ��һ�������ֽ���������$wʹ��һʽ��"+MAG+"������"+NOR+"��ֱ��$n��$l",
    "force" : 140,
    "lvl" : 10,
    "skill_name" : MAG "������" NOR,
    "damage_type" : "����"
]),
([  "action" : "$N�β�ͦ����һʽ��"+YEL+"��ɽ��"+NOR+"��������$w�����ޱȣ������ӽ�ײ��$n��$l",
    "force" : 170,
    "lvl" : 20,
    "skill_name" : YEL "��ɽ��" NOR,
    "damage_type" : "����"
]),
([  "action" : "$Nһʽ��"+BLU+"������"+NOR+"����$w������һ���һ���󻡣�ƽƽ����$n��$l��ȥ",
    "force" : 190,
    "lvl" : 30,
    "skill_name" : BLU "������" NOR,
    "damage_type" : "����"
]),
([  "action" : "$N����š���������鱧��Բ��һʽ��"+BLU+"������"+NOR+"����$w�й�ֱ��������$n���ؿ�",
    "force" : 240,
    "lvl" : 40,
    "skill_name" : BLU "������" NOR,
    "damage_type" : "����"
]),
([  "action" : "$Nһʽ��"+YEL+"������"+NOR+"����$w������������������ֱ����Ю����֮����Ȼն��$n��$l",
    "force" : 280,
    "lvl" : 49,
    "skill_name" : YEL "������" NOR,
    "damage_type" : "����"
]),
([  "action" : "$N����ʩ����"+RED+"������"+NOR+"����$w����Ƴ�һ����â��������ƿ�����$n��$l",
    "force" : 350,
    "lvl" : 57,
    "skill_name" : RED "������" NOR,
    "damage_type" : "����"
]),
([  "action" : "$N˫�Ȱ�����ף�һʽ��"+BLK+"������"+NOR+"�������⻮������ԲȦ����������������",
    "force" : 400,
    "lvl" : 64,
    "skill_name" : BLK "������" NOR,
    "damage_type" : "����"
]),
});
int practice_level(){   return 64;  }
int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }
int valid_combine(string combo) { return combo=="cibei-dao"; }
int valid_learn(object me)
{
    object weapon;
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "sword")
    if (!objectp(weapon = me->query_temp("secondary_weapon"))
    || (string)weapon->query("skill_type") != "sword")
        return notify_fail("��������Ұѽ�������ѧ��ħ����\n");

    if ((int)me->query("max_neili") < 100)
        return notify_fail("�������������\n");
    if ((int)me->query_skill("hunyuan-yiqi", 1) < 20)
    if ((int)me->query_skill("yijing-force", 1) < 20)
    if ((int)me->query_skill("jiuyang-shengong", 1) < 20)
    if ((int)me->query_skill("taiji-shengong", 1) < 20)
        return notify_fail("�������������򲻹����޷�ѧ��ħ����\n");

    if (me->query_skill("sword", 1) <=me->query_skill("fumo-jian", 1))
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
    level   = (int) me->query_skill("fumo-jian",1);
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
    || (string)weapon->query("skill_type") != "sword")
    if (!objectp(weapon = me->query_temp("secondary_weapon"))
    || (string)weapon->query("skill_type") != "sword")
        return notify_fail("��ʹ�õ��������ԡ�\n");
    if ((int)me->query("qi") < 50)
        return notify_fail("���������������ħ����\n");
    me->receive_damage("qi", 35);
    return 1;
}

