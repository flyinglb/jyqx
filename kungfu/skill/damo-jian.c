// damo-jian.c ��Ħ��
inherit SKILL;
mapping *action = ({
([  "action":"$Nʹһʽ��"+MAG+"������Ե��"+NOR+"��������$w����΢�񣬻ó�һ���������$n��$l",
    "force" : 120,
    "lvl" : 0,
    "skill_name" : MAG "������Ե��" NOR,
    "damage_type":  "����"
]),
([  "action":"$N����ǰ��ʹ����"+HIB+"��ȥ������"+NOR+"���������������ޣ�$w��������$n��$l��ȥ",
    "force" : 140,
    "lvl" : 9,
    "skill_name" : HIB "��ȥ������" NOR,
    "damage_type":  "����"
]),
([  "action":"$Nһʽ��"+HIG+"������ɣԶ"+NOR+"��������Ʈ�����ߣ��˷�����������$wңҡָ��$n��$l",
    "force" : 160,
    "lvl" : 18,
    "skill_name" : HIG "������ɣԶ" NOR,
    "damage_type":  "����"
]),
([  "action":"$N��������Ծ��һʽ��"+WHT+"�ֻط�����"+NOR+"�����������ּ�ת������ն��$n��$l",
    "force" : 180,
    "lvl" : 27,
    "skill_name" : WHT "�ֻط�����" NOR,
    "damage_type":  "����"
]),
([  "action":"$N����$w�й�ֱ����һʽ��"+RED+"ˮ��ͨ����"+NOR+"����������Ϣ�ض�׼$n��$l�̳�һ��",
    "force" : 220,
    "lvl" : 36,
    "skill_name" : RED "ˮ��ͨ����" NOR,
    "damage_type":  "����"
]),
([  "action":"$N����$wбָ���죬��â���£�һʽ��"+MAG+"����������"+NOR+"������׼$n��$lбб����",
    "force" : 260,
    "lvl" : 44,
    "skill_name" : MAG "����������" NOR,
    "damage_type":  "����"
]),
([  "action":"$N��ָ�����㣬����$w�Ƴ�����ѩ����â��һʽ��"+HIR+"ǧ��һέȥ"+NOR+"������$n��$l",
    "force" : 320,
    "lvl" : 52,
    "skill_name" : HIR "ǧ��һέȥ" NOR,
    "damage_type":  "����"
]),
([  "action":"$N���Ƶ�����һʽ��"+YEL+"���Ķ�����"+NOR+"����$w�Ի���Ծ�����缲�������$n���ؿ�",
    "force" : 380,
    "lvl" : 60,
    "skill_name" : YEL "���Ķ�����" NOR,
    "damage_type":  "����"
]),
});
int practice_level(){   return 60;  }
int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }
int valid_combine(string combo) { return combo=="xiuluo-dao"; }
int valid_learn(object me)
{
    if ((int)me->query("max_neili") < 150)
        return notify_fail("�������������\n");
    if (me->query_skill("sword", 1) <=me->query_skill("damo-jian", 1))
        return notify_fail("��Ļ����������޷���������ļ��ɡ�\n");
    if ((int)me->query_skill("hunyuan-yiqi", 1) < 20)
    if ((int)me->query_skill("yijing-force", 1) < 20)
    if ((int)me->query_skill("jiuyang-shengong", 1) < 20)
    if ((int)me->query_skill("taiji-shengong", 1) < 20)
        return notify_fail("�������������򲻹����޷�ѧ��Ħ����\n");

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
        level   = (int) me->query_skill("damo-jian",1);
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
    object weapon;
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "sword")
    if (!objectp(weapon = me->query_temp("secondary_weapon"))
    || (string)weapon->query("skill_type") != "sword")
        return notify_fail("��ʹ�õ��������ԡ�\n");
    if ((int)me->query("qi") < 50)
        return notify_fail("���������������Ħ����\n");
    me->receive_damage("qi", 25);
    return 1;
}
string perform_action_file(string action)
{
    return __DIR__"damo-jian/" + action;
}
