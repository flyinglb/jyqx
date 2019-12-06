// meinv-quan.c ��Ůȭ
// By Lgg,1998.9

inherit SKILL;

mapping *action = ({
([      "action" : "$Nʹһ�С�������ġ� ��˫�۽������",
        "force" : 180,
        "dodge" : 5,
        "damage":5,
        "lvl" : 0,
        "skill_name" : "�������",
        "damage_type" : "����"
]),
([      "action" : "$NͻȻ��Ϊ�����ҹ���������䲻���ߵ��ֱ�룬��$n���һ��",
        "force" : 200,
        "dodge" : 5,
        "damage": 10,
        "lvl" : 10,
        "skill_name" : "���ҹ��",
        "damage_type" : "����"
]),
([      "action" : "$N��ʽһ��ɡ�����׹¥�����˵ع������̣�ίʵ�Ѳ�",
        "force" : 230,
        "dodge" : 15,
        "damage": 15,
        "lvl" : 22,
        "skill_name" : "����׹¥",
        "damage_type" : "����"
]),
([      "action" : "$N˫���������£��������಻���ĳ���ԭ���ǡ��ļ��麺����������
ʮ����",
        "force" : 270,
        "dodge" : 5,
        "damage": 30,
        "lvl" : 34,
        "skill_name" : "�ļ��麺",
        "damage_type" : "����"
]),
([      "action" : "$Nʹ�������ߵ��С����Կ��������֮����$n���б��ж�ȥ",
        "force" : 320,
        "dodge" : 10,
        "damage": 40,
        "lvl" : 48,
        "skill_name" : "���ߵ���",
        "damage_type" : "����"
]),
([      "action" : "$Nһʽ��ľ���乭���������籧���£����ּ��Ӷ�������$nĿ�ɿڴ�
",
        "force" : 380,
        "dodge" : 25,
        "damage": 52,
        "lvl" : 60,
        "skill_name" : "ľ���乭",
        "damage_type" : "����"
]),
([      "action" : "$N��Ȼ�����������£�˫�ƴӲ���˼��ĽǶȹ��˹�����ԭ����һ��
���༧��ʫ��",
        "force" : 450,
        "dodge" : 15,
        "damage": 64,
        "lvl" : 71,
        "skill_name" : "�༧��ʫ",
        "damage_type" : "����"
]),
([      "action" : "$Nʹ�С��������ˡ�����֫��ڱܿ��������Ż��ƹ���$n��ǰ��",
        "force" : 530,
        "dodge" : 20,
        "damage": 80,
        "lvl" : 82,
        "skill_name" : "��������",
        "damage_type" : "����"
]),
([      "action" : "$N��ָ���Լ�ͷ����һ�ᣬ��������Ļ��˳�ȥ������΢΢һЦ��ȴ
��һ�С�������װ����",
        "force" : 530,
        "dodge" : 20,
        "damage": 95,
        "lvl" : 95,
        "skill_name" : "������װ",
        "damage_type" : "����"
]),
([      "action" : "$N��$n��ס����ָ������ȴ��һ�С�Ƽ�����񡹡�",
        "force" : 530,
        "dodge" : 20,
        "damage": 111,
        "lvl" : 109,
        "skill_name" : "Ƽ������",
        "damage_type" : "����"
]),
([      "action" : "$NͻȻ������üͷ�����硸�������ġ���˫�����Լ��ؿڹ���",
        "force" : 530,
        "dodge" : 20,
        "damage": 124,
        "lvl" : 129,
        "skill_name" : "��������",
        "damage_type" : "����"
]),
([      "action" : "$N����������ѻ������������������ˮ��Ư��һ�㣬ȴ��һ�С�����
΢����",
        "force" : 530,
        "dodge" : 20,
        "damage": 150,
        "lvl" : 149,
        "skill_name" : "����΢��",
        "damage_type" : "����"
]),
([      "action" : "$Nʹ�С������ǡ����������Լ�����б��һ�ƣ�����������������
�������಻��",
        "force" : 530,
        "dodge" : 20,
        "damage": 180,
        "lvl" : 179,
        "skill_name" : "������",
        "damage_type" : "����"
])
});

int valid_enable(string usage) { return  usage=="unarmed" || usage=="parry"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("����Ůȭ������֡�\n");
        if ((int)me->query_skill("yunv-xinfa", 1) < 10)
                return notify_fail("�����Ů�ķ���򲻹����޷�ѧ��Ůȭ��\n");
        if ((int)me->query("max_neili") < 30)
                return notify_fail("�������̫�����޷�ѧϰ��Ůȭ��\n");
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
        level   = (int) me->query_skill("meinv-quan",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 30)
                return notify_fail("�������̫���ˣ�������ϰ��Ůȭ��\n");
        me->receive_damage("qi", 25);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"meinv-quan/" + action;
}
